#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org
#
# Deeply normalize a tarball by unpacking, scrubbing timestamps/UIDs, and repacking.

# arg
TARBALL="$1"

# check that it exists
if [ ! -f "${TARBALL}" ]; then
	echo "Usage: $0 {tarball}"
    exit 1
fi

# strict mode
set -eu -o pipefail

# the script changes directory, so the path must be absolute
TARBALL=$(cd "$(dirname "${TARBALL}")" && pwd)/$(basename "${TARBALL}")

# create an isolated temporary workspace
TMP_DIR=$(mktemp -d "${TMPDIR:-/tmp}/normalize-distfile.XXXXXX")
trap 'rm -rf "${TMP_DIR}"' EXIT

# unpack the original tarball into our temporary directory
tar -xzpf "${TARBALL}" -C "${TMP_DIR}"

chmod 755 "${TMP_DIR}"

# 1. reset all files, directories, and symlink timestamps to Epoch 0 (1970)
find "${TMP_DIR}" -exec touch -h -d 1970-01-01T00:00:00Z {} +

# 2. re-pack deterministically using bsdtar options:
cd "${TMP_DIR}"
find . -print0 | \
	LC_ALL=C sort -z | \
	tar -czf "${TARBALL}.tmp" \
		--format=bsdtar \
		--gid 0 \
		--uid 0 \
		--uname "" \
		--gname "" \
		--options gzip:!timestamp \
		--no-read-sparse \
		--no-recursion \
		--null \
		-T -

# 3. atomically replace the original file
mv "${TARBALL}.tmp" "${TARBALL}"
