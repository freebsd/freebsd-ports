#!/bin/sh
#
# MAINTAINER: tagattie@FreeBSD.org

PATH=/bin:/usr/bin:/usr/sbin

set -e
set -o pipefail

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_ELECTRON_CREATE_MTREE}" ] && set -x

PREFETCH_TIMESTAMP=61171200	# 1971-12-10 00:00:00 GMT

set -u

usage() {
    cat <<EOF
    Usage: ${0##*/} dirname
EOF
    exit 1
}

if [ $# -ne 1 ]; then
    usage
fi

mtree -cbnSp "$1" | mtree -C | \
awk -f "${SCRIPTSDIR}/electron-normalize-permissions.awk" | \
sed -e "s/time=[0-9.]*/time=${PREFETCH_TIMESTAMP}.000000000/" \
    -e 's/\([gu]id\)=[0-9]*/\1=0/g' \
    -e 's/flags=.*/flags=none/' \
    -e "s|^\.|$1|" \
    -e "s|^${WRKDIR}/||" \
    -e '1d'
