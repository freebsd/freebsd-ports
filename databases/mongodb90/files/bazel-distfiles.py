#!/usr/bin/env python3
"""Print BAZEL_DISTFILES and BAZEL_NPM_DISTFILES for the port Makefile.

Usage: bazel-distfiles.py CACHE REGISTRY DISTINFO SEARCHDIR... \\
           -- CURRENT_BAZEL_DISTFILES CURRENT_BAZEL_NPM_DISTFILES

CACHE is a Bazel repository cache filled by a build with downloads enabled,
REGISTRY the extracted bazel-central-registry and SEARCHDIR are directories
(the source tree and the Bazel external repositories) to search for the URLs
of archives which are not Bazel modules. The current values of the Makefile
variables are used for archives which did not change.

Crates (handled by Makefile.crates) and files of the registry are skipped.
"""

import base64
import hashlib
import json
import os
import re
import sys
import tarfile

URL_RE = re.compile(r"https?://[^\s\"'<>{}]+")
TEMPLATE_RE = re.compile(r"https?://[^\s\"'<>{}]*\{\}[^\s\"'<>{}]*")
TEXT_NAMES = (".bzl", ".bazel", ".json", ".yaml", ".yml", ".lock", "WORKSPACE")


def file_digest(path, algo="sha256"):
    h = hashlib.new(algo)
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def integrity_hex(integrity):
    algo, _, b64 = integrity.partition("-")
    return algo, base64.b64decode(b64).hex()


def hex_b64(hexdigest):
    return base64.b64encode(bytes.fromhex(hexdigest)).decode()


def load_registry(registry):
    """Map module archive digests to (module, url); collect all file digests."""
    archives = {}
    files = set()
    for root, _, names in os.walk(registry):
        for name in names:
            path = os.path.join(root, name)
            files.add(file_digest(path))
            if name != "source.json":
                continue
            with open(path) as f:
                source = json.load(f)
            url = source.get("url") or (source.get("urls") or [None])[0]
            if not source.get("integrity") or not url:
                continue
            module = os.path.basename(os.path.dirname(root))
            key = integrity_hex(source["integrity"])
            # Prefer rules_rust over rules_rust_bindgen for the same archive.
            if key not in archives or len(module) < len(archives[key][0]):
                archives[key] = (module, url)
    return archives, files


def load_distinfo(path):
    digests = {}
    with open(path) as f:
        for line in f:
            m = re.match(r"SHA256 \((.*)\) = ([0-9a-f]{64})$", line.strip())
            if m:
                digests[m.group(2)] = m.group(1)
    return digests


def load_texts(dirs):
    texts = []
    for top in dirs:
        for root, _, names in os.walk(top):
            for name in names:
                if not name.endswith(TEXT_NAMES):
                    continue
                path = os.path.join(root, name)
                try:
                    if os.path.getsize(path) > (8 << 20):
                        continue
                    with open(path, errors="replace") as f:
                        texts.append(f.read())
                except OSError:
                    pass
    return texts


def load_npm(texts):
    """Map sha512 digests from pnpm-lock.yaml files to (name, version)."""
    packages = {}
    key_re = re.compile(r"^\s+'?/?((?:@[^/\s]+/)?[^@\s/']+)@([^:(\s']+)")
    for text in texts:
        if "lockfileVersion" not in text:
            continue
        current = None
        for line in text.splitlines():
            m = key_re.match(line)
            if m and line.rstrip().endswith(":"):
                current = m.groups()
            m = re.search(r"integrity: (sha512-[A-Za-z0-9+/=]+)", line)
            if m and current:
                packages[integrity_hex(m.group(1))[1]] = current
    return packages


def is_crate(path):
    """Every crate published on crates.io contains a Cargo.toml.orig."""
    try:
        with tarfile.open(path) as tar:
            return any(n.count("/") == 1 and n.endswith("/Cargo.toml.orig")
                       for n in tar.getnames())
    except (tarfile.TarError, OSError):
        return False


def find_url(algo, digest, ids, texts, url_ids, templates):
    for canonical_id, url in url_ids.get(algo, {}).items():
        if canonical_id in ids:
            return url
    needles = (digest, hex_b64(digest))
    for text in texts:
        for needle in needles:
            pos = text.find(needle)
            if pos < 0:
                continue
            # A version next to the hash and a URL template elsewhere, like
            # "v1.10.0": "<sha256>" and "https://.../archive/{}.tar.gz".
            line = text[text.rfind("\n", 0, pos) + 1:text.find("\n", pos)]
            for version in re.findall(r"[\"'](v?\d[^\"'\s]*)[\"']", line):
                for template in templates:
                    url = template.replace("{}", version)
                    if hashlib.new(algo, url.encode()).hexdigest() in ids:
                        return url
            window = text[max(0, pos - 2000):pos + 2000]
            urls = [(abs(m.start() - (pos - max(0, pos - 2000))), m.group(0))
                    for m in URL_RE.finditer(window)]
            if urls:
                return min(urls)[1]
    return None


def group_name(name):
    return re.sub(r"[^A-Za-z0-9_]", "_", name)


def entry_for(url, group=None):
    """Return (group, site, distfile) with a unique distfile name."""
    base = url.rstrip("/").rsplit("/", 1)[1]
    m = re.match(r"(.*?)(\.tar\.gz|\.tgz|\.tar\.xz|\.tar\.bz2|\.zip)$", base)
    stem, ext = (m.group(1), m.group(2)) if m else (base, "")
    parts = url.split("/")
    if re.match(r"v?\d", stem) and "github.com" in parts:
        # https://github.com/<owner>/<repo>/archive/[refs/tags/]v1.2.tar.gz
        repo = parts[parts.index("github.com") + 2]
        return (group or group_name(repo), url + "?dummy=/",
                "{}-{}{}".format(repo, stem.lstrip("v"), ext))
    if not re.search(r"\d+\.\d+", stem):
        # No version in the name, use the parent directory.
        return (group or group_name(stem), url + "?dummy=/",
                "{}-{}{}".format(stem, parts[-2], ext))
    return (group or group_name(stem), url[:-len(base)], base)


def main(argv):
    if "--" not in argv or len(argv) < 6:
        sys.exit(__doc__)
    sep = argv.index("--")
    cache, registry, distinfo = argv[1:4]
    search_dirs = argv[4:sep]
    current = argv[sep + 1].split()
    current_npm = argv[sep + 2].split() if len(argv) > sep + 2 else []

    archives, registry_files = load_registry(registry)
    distinfo = load_distinfo(distinfo)
    texts = load_texts(search_dirs)
    npm_packages = load_npm(texts)
    templates = {t for text in texts for t in TEMPLATE_RE.findall(text)}
    url_ids = {}
    for algo in ("sha256", "sha512"):
        url_ids[algo] = {}
        for text in texts:
            for url in URL_RE.findall(text):
                url_ids[algo][hashlib.new(algo, url.encode()).hexdigest()] = url
    known = {}
    for i in range(0, len(current) - 2, 3):
        group, site, distfile = current[i:i + 3]
        known[distfile] = (group, site, distfile)

    entries, npm, unknown, crates = {}, {}, [], []
    for algo in ("sha256", "sha512"):
        top = os.path.join(cache, "content_addressable", algo)
        if not os.path.isdir(top):
            continue
        for digest in sorted(os.listdir(top)):
            ids = {n[3:] for n in os.listdir(os.path.join(top, digest))
                   if n.startswith("id-")}
            if algo == "sha256" and digest in registry_files:
                continue
            if algo == "sha256" and distinfo.get(digest, "").startswith("rust/crates/"):
                continue
            if algo == "sha512" and digest in npm_packages:
                name, version = npm_packages[digest]
                base = "{}-{}.tgz".format(name.rsplit("/", 1)[-1], version)
                site = "https://registry.npmjs.org/{}/-/".format(name)
                npm[base] = ("npm_" + group_name(name.lstrip("@")), site, base)
                continue
            if (algo, digest) in archives:
                module, url = archives[(algo, digest)]
                entry = entry_for(url, group_name(module))
            elif distinfo.get(digest) in known:
                entry = known[distinfo[digest]]
            elif is_crate(os.path.join(top, digest, "file")):
                crates.append("{}/{}".format(algo, digest))
                continue
            else:
                url = find_url(algo, digest, ids, texts, url_ids, templates)
                if url is None:
                    unknown.append("{}/{}".format(algo, digest))
                    continue
                entry = entry_for(url)
            entries[entry[2]] = entry

    def table(name, values):
        lines = ["{}=\t\\".format(name)]
        rows = sorted(values, key=lambda e: e[0])
        for i, (group, site, distfile) in enumerate(rows):
            end = " \\" if i < len(rows) - 1 else ""
            lines.append("\t{} {} {}{}".format(group, site, distfile, end))
        return "\n".join(lines)

    print(table("BAZEL_DISTFILES", entries.values()))
    print(table("BAZEL_NPM_DISTFILES", npm.values()))
    for entry in crates:
        print("Crate not in Makefile.crates (run make make-crates): " + entry,
              file=sys.stderr)
    for entry in unknown:
        print("Unknown cache entry, add it by hand: " + entry, file=sys.stderr)


if __name__ == "__main__":
    main(sys.argv)
