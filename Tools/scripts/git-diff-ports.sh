#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

set -e
set -o pipefail

export LC_ALL=C

##
## git-diff-ports.sh: returns the list of ports with uncommitted changes in the repository
##

# check that packaged dependencies are installed

for dep in git; do
	if ! which -s $dep; then
		echo "error: the '$dep' dependency is missing"
		if [ $dep == "git" ]; then
			echo "... please install the 'git' package"
		fi
		exit 1
	fi
done


# MAIN

git diff HEAD "$@" |
	grep "^diff " |
	grep -v Mk/ |
	grep -v Tools/ |
	sed -E 's|diff --git a/||; s| .*||; s|([^/]+/[^/]+).*|\1|' |
	grep -v '/Makefile$' |
	sort |
	uniq
