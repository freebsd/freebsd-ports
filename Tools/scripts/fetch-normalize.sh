#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org
#
# fetch(1) wrapper: downloads a distfile and normalizes it in place, so that
# the SIZE/checksum in distinfo refer to the normalized file.
# Usage: fetch-normalize.sh {fetch args...}  (arguments as given by do-fetch.sh)

set -eu -o pipefail

SCRIPTDIR=${0%/*}
OUT=
ARGS=

# -S SIZE is dropped: it refers to the normalized file, not to the download
while [ $# -gt 0 ]; do
	case "$1" in
	-S)
		shift 2
		continue
		;;
	-o)
		OUT="$2"
		;;
	esac
		ARGS="${ARGS} \"$1\""
		shift
done

eval "/usr/bin/fetch ${ARGS}"

case "${OUT}" in
*.tar.gz)
	/bin/sh "${SCRIPTDIR}/normalize-distfile.sh" "${OUT}"
	;;
esac
