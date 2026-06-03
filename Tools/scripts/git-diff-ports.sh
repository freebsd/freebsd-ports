#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

set -o pipefail
export LC_ALL=C

# ----- Dependency check ----------------------------------------------
for dep in git; do
	if ! command -v "$dep" >/dev/null 2>&1; then
		echo "error: the '$dep' dependency is missing"
		exit 1
	fi
done

# ----- Repository check -----------------------------------------------
if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1 || \
   ! [ -f "$(git rev-parse --show-toplevel)/Mk/bsd.port.mk" ]; then
	echo "error: not a FreeBSD ports repository"
	exit 1
fi

# ----- Main logic -------------------------------------------------------
# Output the list of ports with uncommitted changes.  If no ports are
# changed the script exits cleanly with no output.

git diff HEAD "$@" |
	grep '^diff ' |
	grep -v Mk |
	sed -E 's|diff --git a/||; s| .*||; s|([^/]+/[^/]+).*|\1|' |
	sort |
	uniq || true

exit 0
