#!/usr/bin/env python3
"""Add files to a content addressable Bazel repository cache.

Usage: bazel-cache-add.py CACHE [PATH ...] [--npm FILE URL ...]

Every PATH (or every file below a directory PATH) is stored by its sha256.
Files given with --npm are stored by their sha512 together with the
canonical id rules_js uses for them: their download URL.
Files are hard linked when possible and copied otherwise.
"""

import hashlib
import os
import shutil
import sys


def add(cache, path, algo="sha256", canonical_id=None):
    h = hashlib.new(algo)
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    entry = os.path.join(cache, "content_addressable", algo, h.hexdigest())
    os.makedirs(entry, exist_ok=True)
    dest = os.path.join(entry, "file")
    if not os.path.exists(dest):
        try:
            os.link(path, dest)
        except OSError:
            shutil.copyfile(path, dest)
    if canonical_id is not None:
        id_hash = hashlib.new(algo, canonical_id.encode()).hexdigest()
        open(os.path.join(entry, "id-" + id_hash), "w").close()


def main(argv):
    if len(argv) < 2:
        sys.exit(__doc__)
    cache = argv[1]
    args = argv[2:]
    count = 0
    while args:
        arg = args.pop(0)
        if arg == "--npm":
            path, url = args.pop(0), args.pop(0)
            add(cache, path, "sha512", url)
            count += 1
        elif os.path.isdir(arg):
            for root, _, files in os.walk(arg):
                for name in files:
                    add(cache, os.path.join(root, name))
                    count += 1
        else:
            add(cache, arg)
            count += 1
    print("Added {} files to {}".format(count, cache))


if __name__ == "__main__":
    main(sys.argv)
