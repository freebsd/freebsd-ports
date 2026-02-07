#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

# This script is intended to be used in fetch targets of Node.js ports.
# It fetches a given Node.js package from npmjs.org along with all its dependencies,
# and creates a tarball with the package and all its dependencies.
# It doesn't build or install the package, just fetches it and its dependencies,
# such that the subsequent build step wouldn't require network access.
# This script generates a package-lock.json file for reproducible builds
# if it doesn't already exist.


set -eu -o pipefail
set -o pipefail

export LC_ALL=C

##
## npmjs-get-latest-version.sh: retrieves the latest version of a given Node.js package as registered on https://registry.npmjs.org
##

# args and env

PACKAGE_NAME="$1"
PACKAGE_VERSION="$2"
PACKAGE_LOCK_JSON="$3"
PACKAGE_TARBALL_OUTPUT="$4"

if [ -z "$PACKAGE_NAME" ] || [ -z "$PACKAGE_VERSION" ] || [ -z "$PACKAGE_LOCK_JSON" ] || [ -z "$PACKAGE_TARBALL_OUTPUT" ]; then
	echo "Usage: $0 <package name> <package version> <package-lock.json> <package tarball output>"
	echo "Example: $0 sharp 0.34.4 outdir/sharp-package-lock.json outdir/sharp-0.34.4.tar.gz"
	exit 1
fi

PACKAGE_NAME_PURE="$(echo $PACKAGE_NAME | sed 's|.*/||')"

if [ -z "$TMPDIR" ]; then
	TMPDIR="/tmp"
fi


# check that packaged dependencies are installed

for dep in npm jq; do
	if ! which $dep >/dev/null 2>&1; then
		echo "error: the '$dep' dependency is missing"
		if [ $dep = "npm" ]; then
			echo "... please install the 'npm' package"
		elif [ $dep = "jq" ]; then
			echo "... please install the 'jq' package"
		fi
		exit 1
	fi
done


# MAIN

# to full paths
if ! echo "${PACKAGE_LOCK_JSON}" | grep -q "^/"; then
	PACKAGE_LOCK_JSON="`pwd`/${PACKAGE_LOCK_JSON}"
fi
if ! echo "${PACKAGE_TARBALL_OUTPUT}" | grep -q "^/"; then
	PACKAGE_TARBALL_OUTPUT="`pwd`/${PACKAGE_TARBALL_OUTPUT}"
fi
if ! echo "${TMPDIR}" | grep -q "^/"; then
	TMPDIR="`pwd`/${TMPDIR}"
fi

# create dirs for output files
mkdir -p "$(dirname "${PACKAGE_LOCK_JSON}")"
mkdir -p "$(dirname "${PACKAGE_TARBALL_OUTPUT}")"
mkdir -p "${TMPDIR}"

# create build dir and change to there
BUILD_DIR="${TMPDIR}/${PACKAGE_NAME_PURE}-${PACKAGE_VERSION}"
rm -rf ${BUILD_DIR}
mkdir ${BUILD_DIR}
cd ${BUILD_DIR}

# either just fetch, or regenarate package-lock.json and fetch
if [ -f $PACKAGE_LOCK_JSON ]; then
	# fail if package-lock.json does not contain the requested package and version
	JSON_NAME=$(jq -r ".packages | .\"node_modules/${PACKAGE_NAME}\" .version" $PACKAGE_LOCK_JSON)
	if [ "$JSON_NAME" != "$PACKAGE_VERSION" ]; then
		echo "error: the existing package-lock.json ($PACKAGE_LOCK_JSON) does not contain the requested package ${PACKAGE_NAME}@${PACKAGE_VERSION}"
		echo "       please delete the existing package-lock.json ($PACKAGE_LOCK_JSON) and re-run this script to regenerate it"
		exit 1
	fi

	# fetch dependencies
	echo "{\"name\":\"${PACKAGE_NAME}-installer\",\"version\":\"1.0.0\",\"dependencies\":{\"${PACKAGE_NAME}\":\"${PACKAGE_VERSION}\"}}" > package.json
	cp $PACKAGE_LOCK_JSON package-lock.json
	HOME=${TMPDIR} npm ci --ignore-scripts --global-style --legacy-peer-deps --omit=dev
else
	# info
	echo "INFO: the file $PACKAGE_LOCK_JSON does not exist, we will attempt to generate it"

	# generate package-lock.json
	echo "{\"name\":\"${PACKAGE_NAME}-installer\",\"version\":\"1.0.0\"}" > package.json
	npm install --package-lock-only --global-style --legacy-peer-deps ${PACKAGE_NAME}@${PACKAGE_VERSION}

	# copy generated package-lock.json to the expected location
	cp package-lock.json ${PACKAGE_LOCK_JSON}

	# info
	echo "INFO: ${PACKAGE_LOCK_JSON} did not exist and was generated"

	# fetch dependencies
	HOME=${TMPDIR} npm ci --ignore-scripts --global-style --legacy-peer-deps --omit=dev
fi

# generate tarball with all dependencies

cd ${TMPDIR}

# Remove files that npm generates inconsistently across environments, breaking reproducibility:
#
# 1. .package-lock.json: npm creates this cache file in node_modules/ recording what was installed.
#    Different npm versions write different content - e.g., npm 11.6.1 includes entries for ALL
#    optional dependencies (with "ideallyInert": true) even for other platforms, while npm 11.6.2
#    only includes actually-installed packages. This causes checksum mismatches between systems.
#
# 2. Empty @-scoped directories: When npm skips platform-specific optional dependencies (e.g.,
#    @img/sharp-wasm32 on x64), some npm versions create empty placeholder directories like
#    @emnapi/ while others don't. These empty directories also cause tarball differences.
#
# Neither file is needed for the build - npm regenerates .package-lock.json during install,
# and empty directories serve no purpose.
find ${PACKAGE_NAME_PURE}-${PACKAGE_VERSION} -name '.package-lock.json' -delete
find ${PACKAGE_NAME_PURE}-${PACKAGE_VERSION} -type d -name '@*' -empty -delete

find ${PACKAGE_NAME_PURE}-${PACKAGE_VERSION} -and -exec touch -h -d 1970-01-01T00:00:00Z {} \;
find ${PACKAGE_NAME_PURE}-${PACKAGE_VERSION} -print0 | sort -z | \
      	tar czf ${PACKAGE_TARBALL_OUTPUT} --format=bsdtar --no-read-sparse --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T -
rm -rf ${PACKAGE_NAME_PURE}-${PACKAGE_VERSION}
echo "INFO: created package tarball with dependencies at: ${PACKAGE_TARBALL_OUTPUT}"
