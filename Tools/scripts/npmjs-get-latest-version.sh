#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

set -e
set -o pipefail

export LC_ALL=C

##
## npmjs-get-latest-version.sh: retrieves the latest version of a given Node.js package as registered on https://registry.npmjs.org
##

# args

PACKAGE_NAME="$1"

if [ -z "$PACKAGE_NAME" ]; then
	echo "Usage: $0 <package-name>"
	echo "Example: $0 @github/copilot"
	echo "Example: $0 express"
	exit 1
fi

# check that packaged dependencies are installed

for dep in curl jq; do
	if ! which $dep >/dev/null 2>&1; then
		echo "error: the '$dep' dependency is missing"
		if [ $dep = "curl" ]; then
			echo "... please install the 'curl' package"
		elif [ $dep = "jq" ]; then
			echo "... please install the 'jq' package"
		fi
		exit 1
	fi
done


# MAIN

curl -H "Accept: application/json" https://registry.npmjs.org/$PACKAGE_NAME/latest 2>/dev/null |
	grep -v "Not Found" |
	jq -r '.version' ||
	! echo "failed to find the Node.js package '$PACKAGE_NAME'"
