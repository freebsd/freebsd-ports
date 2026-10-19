#!/usr/bin/env python3
"""Convert a binary Bazel workspace-rules log to FreeBSD Ports definitions.

Usage: python3 files/bazel-fetch-log.py work/*/bazel-fetch.log > Makefile.distfiles

Multiple logs are merged before deduplication and filename-collision handling.
Use bazel-fetch-matrix.py for collection and checked publication of all supported
Bazel versions. Direct log conversion does not validate collection completeness.

Input is --experimental_workspace_rules_log_file output, NOT parser text.
Only Python's standard library is required. The wire-format reader implements
the relevant fields of Bazel 9.2.0's workspace_log.proto:
https://github.com/bazelbuild/bazel/blob/9.2.0/src/main/java/com/google/devtools/build/lib/bazel/debug/workspace_log.proto

Download events record requests, not success. Cached/skipped repository rules
and downloads performed by external commands may be absent. Review the result,
keep these files out of EXTRACT_ONLY, run make makesum, and test offline.
GitHub /archive/*.tar.gz URLs use GH_TUPLE; all other URLs use MASTER_SITES
and DISTFILES. Stage GitHub distfiles under Bazel's original basenames and
verify the hashes before offline use. ZIP files are never converted.
Query URLs use Ports' &dummy=/ convention and the logged output basename
when the URL has none. Unchecksummed metadata needs separate Bazel handling.
Conflicting basenames with SHA256 checksums are stored in separate
bazel/sha256/<digest>/ directories and emit additional BAZEL_DISTDIR_FLAGS.
Local BCR downloads emit deduplicated BAZEL_DISTDIR_FLAGS using ${WRKSRC_bcr}.
Use --bcr-root for an explicit registry path; otherwise a directory named
bazel-central-registry or bazel-central-registry-* is inferred from file URLs.
"""

import argparse
import base64
import binascii
import re
import sys
from pathlib import Path
from urllib.parse import unquote, urlsplit


def varint(data, pos):
    """Read an unsigned protobuf varint, rejecting truncation and overflow."""
    value = 0
    for shift in range(0, 70, 7):
        if pos >= len(data):
            raise ValueError("truncated protobuf varint")
        byte = data[pos]
        pos += 1
        if shift == 63 and byte > 1:
            raise ValueError("protobuf varint overflow")
        value |= (byte & 127) << shift
        if byte < 128:
            return value, pos
    raise ValueError("invalid protobuf varint")


def fields(data):
    """Yield length-delimited fields; safely skip other supported wire types."""
    pos = 0
    while pos < len(data):
        tag, pos = varint(data, pos)
        number, wire = tag >> 3, tag & 7
        if not 0 < number < 2**29:
            raise ValueError("invalid protobuf field number")
        if wire == 0:
            _, pos = varint(data, pos)
        elif wire in (1, 2, 5):
            if wire == 2:
                size, pos = varint(data, pos)
            else:
                size = 8 if wire == 1 else 4
            end = pos + size
            if end > len(data):
                raise ValueError("truncated protobuf field")
            if wire == 2:
                yield number, data[pos:end]
            pos = end
        else:
            raise ValueError(f"unsupported protobuf wire type {wire}")


def downloads(data):
    pos = 0
    while pos < len(data):
        offset = pos
        size, pos = varint(data, pos)
        end = pos + size
        if end > len(data):
            raise ValueError(f"truncated WorkspaceEvent at byte {offset}")
        for number, event in fields(data[pos:end]):
            if number not in (4, 5):
                continue
            values = {}
            # Download.integrity = 5; DownloadAndExtract.integrity = 6.
            integrity_field = 5 if number == 4 else 6
            for key, raw in fields(event):
                if key in (1, 2, 3, integrity_field):
                    values.setdefault(key, []).append(raw.decode("utf-8"))
            yield (values.get(1, []), values.get(3, [""])[-1],
                   values.get(integrity_field, [""])[-1],
                   values.get(2, [""])[-1])
        pos = end


def checksum(sha256, integrity):
    """Normalize SHA256/SRI for duplicate and filename-collision detection."""
    if sha256 and not re.fullmatch(r"[0-9a-fA-F]{64}", sha256):
        raise ValueError(f"invalid SHA256: {sha256!r}")
    sha256 = sha256.lower()
    tokens = integrity.split()
    for token in tokens:
        if token.startswith("sha256-"):
            try:
                digest = base64.b64decode(token[7:], validate=True)
            except binascii.Error as exc:
                raise ValueError("invalid SHA256 integrity") from exc
            if len(digest) != 32 or (sha256 and sha256 != digest.hex()):
                raise ValueError("inconsistent SHA256 and integrity")
            sha256 = digest.hex()
    return "sha256:" + sha256 if sha256 else " ".join(sorted(tokens))


def github_tuple(url):
    """Recognize GitHub-generated tar.gz archives, not release assets or ZIPs."""
    parsed = urlsplit(url)
    if (parsed.scheme not in ("http", "https") or parsed.netloc != "github.com"
            or parsed.query or parsed.fragment):
        return None
    match = re.fullmatch(
        r"/([A-Za-z0-9_.-]+)/([A-Za-z0-9_.-]+)/archive/(?:refs/tags/)?(.+)\.tar\.gz",
        parsed.path,
    )
    if not match:
        return None
    account, project, ref = match.groups()
    ref = unquote(ref)
    if not re.fullmatch(r"[A-Za-z0-9_+.-]+(?:/[A-Za-z0-9_+.-]+)*", ref):
        raise ValueError(f"ref cannot be represented safely in GH_TUPLE: {url!r}")
    return account, project, ref


def bcr_distdir(url, bcr_root):
    """Return a relocatable parent directory for a local registry input."""
    parsed = urlsplit(url)
    if parsed.netloc not in ("", "localhost") or parsed.query or parsed.fragment:
        raise ValueError(f"unsupported local file URL: {url!r}")
    path = Path(unquote(parsed.path))
    if not path.is_absolute():
        raise ValueError(f"file URL must be absolute: {url!r}")
    path = path.resolve()
    if bcr_root is None:
        bcr_root = next((parent for parent in path.parents
                         if parent.name == "bazel-central-registry"
                         or parent.name.startswith("bazel-central-registry-")), None)
    if bcr_root is None:
        return None
    try:
        relative = path.relative_to(bcr_root)
    except ValueError:
        return None
    directory = relative.parent.as_posix()
    if not re.fullmatch(r"[A-Za-z0-9_./+-]+", directory):
        raise ValueError(f"BCR path needs manual Makefile handling: {url!r}")
    return "${WRKSRC_bcr}" + ("/" + directory if directory != "." else "")


def definitions(data, bcr_root=None):
    """Merge streams before assigning names, groups, and collision directories."""
    entries = {}
    github = {}
    distdirs = set()
    if bcr_root is not None:
        bcr_root = Path(bcr_root).resolve()
    warnings = set()
    count = 0
    streams = [data] if isinstance(data, bytes) else data
    for urls, sha256, integrity, output in (event for stream in streams
                                           for event in downloads(stream)):
        count += 1
        digest = checksum(sha256, integrity)

        # rules_go optionally queries this mutable SDK index.
        # Without a checksum, --distdir cannot satisfy this request.
        go_sdk_indexes = {
            "https://go.dev/dl/?mode=json&include=all",
            "https://golang.google.cn/dl/?mode=json&include=all",
        }
        if (
            not digest
            and urls
            and all(url in go_sdk_indexes for url in urls)
        ):
            warnings.add(
                "Omitted optional Go SDK version index from DISTFILES; "
                "verify the required targets with downloads disabled."
            )
            continue

        remote = []
        for url in urls:
            parsed = urlsplit(url)
            if parsed.scheme == "file":
                directory = bcr_distdir(url, bcr_root)
                if directory is None:
                    warnings.add(f"Local input outside the BCR was omitted: {url}; "
                                 "use --bcr-root if this is registry data.")
                else:
                    distdirs.add(directory)
                continue
            if parsed.scheme not in ("http", "https", "ftp"):
                raise ValueError(f"unsupported download URL: {url!r}")
            # Reject syntax that cannot safely be pasted into a Ports Makefile.
            if (not parsed.netloc or parsed.username is not None
                    or parsed.fragment
                    or re.search(r'[\s$#\\\x00-\x1f\x7f]', url)
                    or "%SUBDIR%" in url):
                raise ValueError(f"URL needs manual MASTER_SITES handling: {url!r}")
            name = parsed.path.rsplit("/", 1)[-1]
            if not name and parsed.query:
                name = output.rsplit("/", 1)[-1]
            if not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9._+%-]*", name):
                raise ValueError(f"unsafe or missing distfile name: {url!r}")
            remote.append((name, url))
        if not remote:
            continue
        tuples = {github_tuple(url) for _, url in remote} - {None}
        if len(tuples) > 1:
            raise ValueError("download mirrors refer to different GitHub archives")
        if tuples:
            key = tuples.pop()
            if key in github:
                old_digest, sources = github[key]
                if old_digest != digest:
                    raise ValueError(f"conflicting checksums for GitHub archive {key!r}")
                sources.update(url for _, url in remote)
            else:
                github[key] = (digest, {url for _, url in remote})
            if not digest:
                warnings.add(f"{key}: no checksum in log; verify the GitHub archive before make makesum.")
            continue
        name = remote[0][0]
        sources = {url for n, url in remote if n == name}
        if any(n != name for n, _ in remote):
            warnings.add(f"{name}: mirrors with different basenames were omitted.")
        variants = entries.setdefault(name, {})
        if digest in variants:
            if not digest and not variants[digest].intersection(sources):
                raise ValueError(f"conflicting downloads named {name!r} without SHA256; "
                                 "rename/stage them explicitly")
            variants[digest].update(sources)
        else:
            variants[digest] = sources
        if not digest:
            warnings.add(f"{name}: no checksum in log; verify the fetched file before make makesum.")
            if any(urlsplit(url).query for _, url in remote):
                warnings.add(f"{name}: unchecksummed query metadata cannot be supplied via --distdir alone; "
                             "pin its contents and checksum in the Bazel rule or avoid this lookup.")
    if not count:
        raise ValueError("no download events found (expected a binary Bazel workspace-rules log)")
    distfiles = []
    for name, variants in sorted(entries.items()):
        conflicting = len(variants) > 1
        for digest, sources in sorted(variants.items()):
            filename = name
            if conflicting:
                if not re.fullmatch(r"sha256:[0-9a-f]{64}", digest):
                    raise ValueError(f"conflicting downloads named {name!r} without SHA256; "
                                     "rename/stage them explicitly")
                directory = "bazel/sha256/" + digest.removeprefix("sha256:")
                filename = directory + "/" + name
                distdirs.add("${DISTDIR}/${DIST_SUBDIR}/" + directory)
            # do-fetch.sh strips ?dummy=/ or &dummy=/ and uses -o to save
            # the exact URL under the DISTFILES path, including subdirectories.
            sites = {url + ("&dummy=/" if urlsplit(url).query else "?dummy=/")
                     if conflicting or urlsplit(url).query
                     else url.rsplit("/", 1)[0] + "/"
                     for url in sources}
            distfiles.append((filename, digest, sites))
    lines = ["# Generated from Bazel download requests; review before inclusion.",
             "# Keep these files out of EXTRACT_ONLY; run make makesum."]
    if distdirs:
        lines += ["", "# Local BCR inputs and directories for conflicting download basenames."]
        for directory in sorted(distdirs):
            lines.append(f'BAZEL_DISTDIR_FLAGS+=\t--distdir="{directory}"')
    if github:
        lines += ["", ".if !defined(USE_GITHUB)", "USE_GITHUB=\tnodefault", ".endif"]
    for index, (key, (digest, sources)) in enumerate(sorted(github.items()), 1):
        group = f"bazelgh{index:04d}"
        lines.append("")
        if digest:
            lines.append(f"# {digest}")
        for url in sorted(sources):
            lines.append(f"# Bazel URL: {url}")
        lines.append(f"GH_TUPLE+=\t{':'.join(key)}:{group}")
        lines.append(
            f'BAZEL_DISTDIR_FLAGS+=\t--distdir="${{WRKDIR}}/bazel-distdir/{group}"'
        )
        names = sorted({
            urlsplit(url).path.rsplit("/", 1)[-1]
            for url in sources
        })
        for name in names:
            lines.append(
                f"BAZEL_GH_DISTFILES+=\t"
                f"${{DISTFILE_{group}}}:{group}/{name}"
            )
    for index, (name, digest, sites) in enumerate(distfiles, 1):
        group = f"bazelfetch{index:04d}"
        lines.append("")
        if digest:
            lines.append(f"# {digest}")
        for site in sorted(sites):
            lines.append(f"MASTER_SITES+=\t{site}:{group}")
        lines.append(f"DISTFILES+=\t{name}:{group}")
    return "\n".join(lines) + "\n", warnings, len(distfiles) + len(github)


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("logfile", type=Path, nargs="+",
                        help="binary Bazel workspace-rules logs to merge")
    parser.add_argument("--bcr-root", type=Path,
                        help="local registry root to replace with ${WRKSRC_bcr}")
    args = parser.parse_args()
    try:
        streams = [path.read_bytes() for path in args.logfile]
        # Reject an empty input even if another log contains download events.
        for path, stream in zip(args.logfile, streams):
            if not any(downloads(stream)):
                raise ValueError(f"no download events in {path}")
        output, warnings, count = definitions(streams, args.bcr_root)
    except (OSError, ValueError) as exc:
        print(f"{parser.prog}: error: {exc}", file=sys.stderr)
        return 1
    for warning in sorted(warnings):
        print(f"warning: {warning}", file=sys.stderr)
    print(f"{count} distfiles; requests in this log may be incomplete or unsuccessful.",
          file=sys.stderr)
    sys.stdout.write(output)
    return 0


if __name__ == "__main__":
    sys.exit(main())
