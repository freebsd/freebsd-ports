#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

set -e
set -o pipefail

export LC_ALL=C

##
## git-get-latest-remote-version.sh: retrieves the latest version of a given Git project on github.com
##

# args

REPOSITORY_URL="$1"
TAG_PREFIX="$2"

if [ -z "$REPOSITORY_URL" ]; then
	echo "Usage: $0 <repository-url> <tag-prefix>"
	exit 1
fi

# check that packaged dependencies are installed

for dep in git version_sort; do
	if ! which -s $dep; then
		echo "error: the '$dep' dependency is missing"
		if [ $dep == "git" ]; then
			echo "... please install the 'git' package"
		elif [ $dep == "version_sort" ]; then
			echo "... please install the 'libversion' package"
		fi
		exit 1
	fi
done


# MAIN

git ls-remote --refs --tags $REPOSITORY_URL 2>/dev/null |
	grep "refs/tags/$TAG_PREFIX" |
	sed -e "s|.*refs/tags/$TAG_PREFIX||" |
	version_sort |
	tail -1 ||
	! echo "failed to find the git project or tags in it"
