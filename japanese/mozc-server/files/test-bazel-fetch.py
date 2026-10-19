#!/usr/bin/env python3
"""Regression checks for merging independent fetch logs and publication failures."""
import argparse
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest
import sys
from unittest.mock import patch

sys.dont_write_bytecode = True

HERE = Path(__file__).resolve().parent


def load(name, filename):
    spec = importlib.util.spec_from_file_location(name, HERE / filename)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


logs = load("logs", "bazel-fetch-log.py")
matrix = load("matrix", "bazel-fetch-matrix.py")


def varint(value):
    result = bytearray()
    while value >= 128:
        result.append((value & 127) | 128)
        value >>= 7
    return bytes(result + bytes([value]))


def field(number, value):
    value = value.encode() if isinstance(value, str) else value
    return varint(number * 8 + 2) + varint(len(value)) + value


def event(url, sha256):
    request = field(1, url) + field(3, sha256)
    message = field(5, request)
    return varint(len(message)) + message


class MergeTests(unittest.TestCase):
    def test_union_deduplicates_and_sorts(self):
        first = event("https://example.org/a.tar.gz", "a" * 64)
        second = event("https://example.org/b.tar.gz", "b" * 64)
        output, _, count = logs.definitions([first, second, first])
        self.assertEqual(count, 2)
        self.assertEqual(output, logs.definitions([second, first])[0])

    def test_collision_across_versions(self):
        first = event("https://one.example/archive.tar.gz", "a" * 64)
        second = event("https://two.example/archive.tar.gz", "b" * 64)
        output, _, count = logs.definitions([first, second])
        self.assertEqual(count, 2)
        for digest in ("a" * 64, "b" * 64):
            self.assertIn("bazel/sha256/" + digest + "/archive.tar.gz", output)

    def test_distinct_bcr_roots_are_relocatable(self):
        streams = [event(f"file:///tmp/{v}/bazel-central-registry-abc/modules/x/1/MODULE.bazel",
                         "a" * 64) for v in ("9.2.0", "9.3.0")]
        output, _, _ = logs.definitions(streams)
        self.assertEqual(output.count('${WRKSRC_bcr}/modules/x/1"'), 1)
        self.assertNotIn("/tmp/", output)

    def test_truncated_second_log_fails(self):
        good = event("https://example.org/a.tar.gz", "a" * 64)
        with self.assertRaises(ValueError):
            logs.definitions([good, good[:-1]])


class PublishTests(unittest.TestCase):
    def test_successful_matrix_and_missing_version(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "Makefile").touch()
            (root / "files").mkdir()
            entries = [{"version": v, "commit": "abc"}
                       for v in ("9.0.1", "9.1.0", "9.1.1", "9.2.0", "9.3.0")]
            versions = root / "versions.json"
            versions.write_text(json.dumps(entries))
            args = argparse.Namespace(versions=versions, bin_dir=root / "bin",
                                      work_root=root / "work", port=root,
                                      make="make", make_arg=[], output=root / "generated")

            def fake_version(command, **kwargs):
                return "bazel " + Path(command[0]).parent.name + "\n"

            def fake_fetch(command, **kwargs):
                work = Path(next(arg[7:] for arg in command if arg.startswith("WRKDIR=")))
                work.mkdir(parents=True, exist_ok=True)
                logfile = next((Path(arg.split("=", 1)[1]) for arg in command
                                if arg.startswith("BAZEL_FETCH_LOG=")), work / "bazel-fetch.log")
                logfile.write_bytes(
                    event("https://example.org/a.tar.gz", "a" * 64))

            with patch.object(matrix.subprocess, "check_output", side_effect=fake_version), \
                    patch.object(matrix.subprocess, "run", side_effect=fake_fetch):
                matrix.collect(args)
            matrix.generate(args)
            self.assertIn("9.0.1, 9.1.0, 9.1.1, 9.2.0, 9.3.0", args.output.read_text())
            self.assertEqual(args.output.read_text().count("DISTFILES+="), 1)
            manifest_path = args.work_root / "manifest.json"
            original_manifest = manifest_path.read_bytes()
            with patch.object(matrix.subprocess, "check_output", side_effect=fake_version), \
                    patch.object(matrix.subprocess, "run", side_effect=fake_fetch) as run:
                matrix.collect(args, offline=True)
                self.assertEqual(run.call_count, 5)
                for call in run.call_args_list:
                    command = call.args[0]
                    self.assertIn("BAZEL_FETCH_FLAGS=--repository_disable_download", command)
                    self.assertTrue(any(arg.startswith("BAZEL_FETCH_OUTPUT=") for arg in command))
                    self.assertTrue(any(arg.startswith("BAZEL_FETCH_CACHE=") for arg in command))
            self.assertEqual(manifest_path.read_bytes(), original_manifest)
            manifest = json.loads(manifest_path.read_text())
            manifest["versions"].pop()
            manifest_path.write_text(json.dumps(manifest))
            old = args.output.read_bytes()
            with self.assertRaises(ValueError):
                matrix.generate(args)
            self.assertEqual(args.output.read_bytes(), old)

    def test_incomplete_or_modified_collection_preserves_output(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            versions = root / "versions.json"
            entries = [{"version": "9.2.0", "commit": "abc"}]
            versions.write_text(json.dumps(entries))
            output = root / "Makefile.distfiles"
            output.write_text("original\n")
            logfile = root / "fetch.log"
            logfile.write_bytes(event("https://example.org/a.tar.gz", "a" * 64))
            manifest = {"schema": 1, "versions": [dict(entries[0], log=str(logfile),
                                                      sha256=matrix.digest(logfile))]}
            (root / "manifest.json").write_text(json.dumps(manifest))
            args = argparse.Namespace(work_root=root, versions=versions, output=output)
            (root / "pending").touch()
            with self.assertRaises(ValueError):
                matrix.generate(args)
            self.assertEqual(output.read_text(), "original\n")
            (root / "pending").unlink()
            args.port = root
            (root / "Makefile").touch()
            (root / "files").mkdir()
            manifest["inputs"] = matrix.inputs(root)
            (root / "manifest.json").write_text(json.dumps(manifest))
            logfile.write_bytes(logfile.read_bytes() + b"\x80")
            with self.assertRaises(ValueError):
                matrix.generate(args)
            self.assertEqual(output.read_text(), "original\n")


if __name__ == "__main__":
    unittest.main()
