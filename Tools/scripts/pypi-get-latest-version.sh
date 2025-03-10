#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

set -e
set -o pipefail

export LC_ALL=C

##
## pypi-get-latest-version.sh: retrieves the latest version of a given Python package as registered on https://pypi.org
##

# args

PACKAGE_NAME="$1"

if [ -z "$PACKAGE_NAME" ]; then
	echo "Usage: $0 <package-name>"
	exit 1
fi

# check that packaged dependencies are installed

for dep in jq version_sort; do
	if ! which -s $dep; then
		echo "error: the '$dep' dependency is missing"
		if [ $dep == "jq" ]; then
			echo "... please install the 'jq' package"
		elif [ $dep == "version_sort" ]; then
			echo "... please install the 'libversion' package"
		fi
		exit 1
	fi
done


# MAIN

fetch -o - https://pypi.python.org/pypi/$PACKAGE_NAME/json 2>/dev/null |
	jq -r '.releases | keys[]' |
	grep -v dev |
	grep -v -E ".*(a|b|rc)[0-9]*$" |
	version_sort |
	tail -1 ||
	! echo "failed to find the Python package '$PACKAGE_NAME'"
