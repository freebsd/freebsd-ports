#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

set -e
set -o pipefail

export LC_ALL=C

##
## hackage-get-latest-version.sh: retrieves the latest version of a given Haskell package as registered on https://hackage.haskell.org
##

# args

PACKAGE_NAME="$1"

if [ -z "$PACKAGE_NAME" ]; then
	echo "Usage: $0 <package-name>"
	exit 1
fi

# check that packaged dependencies are installed

for dep in curl jq version_sort; do
	if ! which -s $dep; then
		echo "error: the '$dep' dependency is missing"
		if [ $dep == "curl" ]; then
			echo "... please install the 'curl' package"
		elif [ $dep == "jq" ]; then
			echo "... please install the 'jq' package"
		elif [ $dep == "version_sort" ]; then
			echo "... please install the 'libversion' package"
		fi
		exit 1
	fi
done


# MAIN

curl -H "Accept: application/json" https://hackage.haskell.org/package/$PACKAGE_NAME 2>/dev/null |
	grep -v "Package not found: No such package in package index" |
	jq -r 'keys[]' |
	version_sort |
	tail -1 ||
	! echo "failed to find the Python package '$PACKAGE_NAME'"
