#!/usr/bin/env python3
"""Collect independent Bazel fetch logs and atomically generate their union.

Provision FreeBSD Bazel executables in BIN_DIR/VERSION/bazel first. Historical
port commits are recorded in bazel-versions.json; no installed package is changed.
Use `versions --ports-root /usr/ports` to refresh that list from Git history.
Use `fetch --bin-dir ... --work-root ...` then `generate --work-root ...`.
A successful fetch publishes a manifest only after every version succeeds.

The corresponding port targets are update-bazel-versions, update-bazel-fetch-all,
and update-bazel-distfiles. Set BAZEL_BIN_DIR to the executable directory; each
VERSION/bazel may be a symlink. Run make makesum after generation and verify
with verify-bazel-distfiles: it fetches the same targets with fresh output and
download caches, the repo contents cache disabled, and downloads forbidden.
"""

import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import shlex
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
sys.dont_write_bytecode = True


def atomic_write(path, content):
    path = Path(path)
    with tempfile.NamedTemporaryFile(mode="w", dir=path.parent,
                                     prefix=path.name + ".", delete=False) as out:
        temporary = Path(out.name)
        try:
            out.write(content)
            out.close()
            temporary.chmod(path.stat().st_mode & 0o777 if path.exists() else 0o644)
            temporary.replace(path)
        finally:
            temporary.unlink(missing_ok=True)


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def inputs(port):
    """Detect source/patch changes between collection and publication."""
    paths = [port / "Makefile", *(port / "files").iterdir()]
    return {str(path.relative_to(port)): digest(path) for path in sorted(paths)
            if path.is_file() and path.name != "Makefile.distfiles"}


def version_list(path):
    entries = json.loads(Path(path).read_text())
    versions = [entry["version"] for entry in entries]
    if (not versions or len(versions) != len(set(versions))
            or any(not re.fullmatch(r"9\.\d+\.\d+", v) for v in versions)):
        raise ValueError("expected a nonempty list of distinct Bazel 9 versions")
    return entries


def history(root):
    def git(*args):
        return subprocess.check_output(["git", "-C", str(root), *args], text=True)
    commits = git("log", "--reverse", "--format=%H", "--",
                  "devel/bazel9/Makefile").splitlines()
    entries = {}
    for commit in commits:
        contents = git("show", f"{commit}:devel/bazel9/Makefile")
        match = re.search(r"^DISTVERSION=\s*(9\.\d+\.\d+)\s*$", contents, re.M)
        if not match:
            raise ValueError(f"cannot read DISTVERSION at {commit}")
        entries.setdefault(match[1], {"version": match[1], "commit": commit})
    return sorted(entries.values(), key=lambda e: tuple(map(int, e["version"].split("."))))


def collect(args, offline=False):
    entries = version_list(args.versions)
    original_inputs = inputs(args.port)
    protected = {"WRKDIR", "BAZEL_CMD", "BAZEL_FETCH_LOG", "BAZEL_FETCH_OUTPUT",
                 "BAZEL_FETCH_CACHE", "BAZEL_FETCH_FLAGS"}
    for argument in args.make_arg:
        name, separator, _ = argument.partition("=")
        if not separator or not re.fullmatch(r"[A-Z_][A-Z_0-9]*", name) or name in protected:
            raise ValueError(f"unsupported make assignment: {argument}")
    # Check all executables before starting potentially expensive fetches.
    for entry in entries:
        executable = (args.bin_dir / entry["version"] / "bazel").resolve()
        actual = subprocess.check_output([str(executable), "--version"], text=True).strip()
        if actual != "bazel " + entry["version"]:
            raise ValueError(f"{executable}: expected bazel {entry['version']}, got {actual}")
        entry["executable"] = str(executable)
    args.work_root.mkdir(parents=True, exist_ok=True)
    if offline:
        previous = json.loads((args.work_root / "manifest.json").read_text())["versions"]
        if [e["version"] for e in previous] != [e["version"] for e in entries]:
            raise ValueError("collect all supported versions before verification")
        workdirs = {e["version"]: Path(e["log"]).parent for e in previous}
    prefix = "verify-" if offline else "run-"
    run = Path(tempfile.mkdtemp(prefix=prefix, dir=args.work_root)).resolve()
    pending = args.work_root / "pending"
    if not offline:
        atomic_write(pending, str(run) + "\n")
    for entry in entries:
        version = entry["version"]
        work = workdirs[version] if offline else run / version
        console = run / (version + ".console.log")
        print(f"Fetching with Bazel {version}; log: {console}", flush=True)
        executable = shlex.quote(entry["executable"])
        extra = []
        if offline:
            extra = ["post-configure-bazel-distdir",
                     "BAZEL_FETCH_LOG=" + str(run / (version + ".fetch.log")),
                     "BAZEL_FETCH_OUTPUT=" + str(run / version / "output"),
                     "BAZEL_FETCH_FLAGS=--repository_disable_download"]
        command = [args.make, "-C", str(args.port), *extra, "update-bazel-fetch",
                   f"BAZEL_CMD={executable}", f"WRKDIR={work}",
                   *args.make_arg]
        if offline:
            # The normal fetch recipe also disables the repo contents cache.
            # Override its download cache without changing the source tree.
            command.append("BAZEL_FETCH_CACHE=" + str(run / version / "cache"))
        with console.open("w") as out:
            subprocess.run(command, stdout=out, stderr=subprocess.STDOUT, check=True)
        logfile = run / (version + ".fetch.log") if offline else work / "bazel-fetch.log"
        entry["log"] = str(logfile)
        entry["sha256"] = digest(logfile)
    if original_inputs != inputs(args.port):
        raise ValueError("port inputs changed during collection; rerun fetch")
    if offline:
        atomic_write(run / "verified.json", json.dumps(entries, indent=2) + "\n")
        print(f"Offline fetch passed for all {len(entries)} versions; results: {run}")
        return
    manifest = {"schema": 1, "versions": entries, "inputs": original_inputs}
    atomic_write(args.work_root / "manifest.json", json.dumps(manifest, indent=2) + "\n")
    pending.unlink()


def generate(args):
    if (args.work_root / "pending").exists():
        raise ValueError("latest collection did not finish; rerun fetch before generating")
    expected = version_list(args.versions)
    manifest = json.loads((args.work_root / "manifest.json").read_text())
    entries = manifest["versions"]
    if (manifest.get("schema") != 1
            or [(e["version"], e["commit"]) for e in entries]
            != [(e["version"], e["commit"]) for e in expected]):
        raise ValueError("manifest does not match the supported version list; rerun fetch")
    if manifest["inputs"] != inputs(args.port):
        raise ValueError("port inputs changed since collection; rerun fetch")
    spec = importlib.util.spec_from_file_location("fetch_log", HERE / "bazel-fetch-log.py")
    parser = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(parser)
    streams = []
    required_by = {}
    for entry in entries:
        path = Path(entry["log"])
        if digest(path) != entry["sha256"]:
            raise ValueError(f"log changed since successful fetch: {path}")
        stream = path.read_bytes()
        if not any(parser.downloads(stream)):
            raise ValueError(f"no download events: {path}")
        for urls, sha256, integrity, _ in parser.downloads(stream):
            key = parser.checksum(sha256, integrity)
            if key:
                required_by.setdefault(key, set()).add(entry["version"])
        streams.append(stream)
    # Infer each local BCR root from its URL, as every run has a separate WRKDIR.
    output, warnings, count = parser.definitions(streams)
    lines = []
    for line in output.splitlines():
        if line.startswith("# ") and line[2:] in required_by:
            versions = sorted(required_by[line[2:]],
                              key=lambda v: tuple(map(int, v.split("."))))
            lines.append("# Required by Bazel: " + ", ".join(versions))
        lines.append(line)
    output = "\n".join(lines) + "\n"
    provenance = "# Bazel versions: " + ", ".join(e["version"] for e in entries) + "\n"
    for warning in sorted(warnings):
        print("warning: " + warning, file=sys.stderr)
    atomic_write(args.output, provenance + output)
    print(f"Generated {args.output}: {count} distfiles from {len(entries)} Bazel versions")


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("action", choices=("versions", "fetch", "generate", "verify"))
    parser.add_argument("--versions", type=Path, default=HERE / "bazel-versions.json")
    parser.add_argument("--ports-root", type=Path, default=HERE.parents[2])
    parser.add_argument("--port", type=Path, default=HERE.parent)
    parser.add_argument("--bin-dir", type=Path)
    parser.add_argument("--work-root", type=Path, default=HERE.parent / "work-bazel-matrix")
    parser.add_argument("--output", type=Path, default=HERE / "Makefile.distfiles")
    parser.add_argument("--make", default="make")
    parser.add_argument("--make-arg", action="append", default=[],
                        help="extra make variable assignment, e.g. MAKE_JOBS_NUMBER=4")
    args = parser.parse_args()
    try:
        if args.action == "versions":
            entries = history(args.ports_root)
            if not entries:
                raise ValueError("no Bazel 9 versions found in Git history")
            atomic_write(args.versions, json.dumps(entries, indent=2) + "\n")
        elif args.action in ("fetch", "verify"):
            if args.bin_dir is None:
                parser.error("fetch requires --bin-dir")
            collect(args, offline=args.action == "verify")
        else:
            generate(args)
    except (OSError, ValueError, KeyError, subprocess.CalledProcessError) as exc:
        print(f"{parser.prog}: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
