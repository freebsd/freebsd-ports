#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_CHECKSUM_ALGORITHMS dp_CKSUMFILES dp_DISTDIR dp_DISTINFO_FILE \
	dp_ECHO_MSG

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_MAKESUM}" ] && set -x

set -u

DISTINFO_OLD=$(mktemp -t makesum-old)
DISTINFO_NEW=$(mktemp -t makesum-new)

trap 'rm -f ${DISTINFO_OLD} ${DISTINFO_NEW}' EXIT INT TERM

check_checksum_algorithms

cd "${dp_DISTDIR}"

# Running `make makesum` a twice should not change the timestamp generated from
# the first run.
# So, we extract the content of the distinfo file minus the TIMESTAMP, if it
# contains a TIMESTAMP.
if [ -f "${dp_DISTINFO_FILE}" ] && grep -q "^TIMESTAMP " ${dp_DISTINFO_FILE}; then
	grep -v "^TIMESTAMP " ${dp_DISTINFO_FILE} > ${DISTINFO_OLD}
fi

for file in ${dp_CKSUMFILES}; do
	for alg in ${dp_CHECKSUM_ALGORITHMS}; do
		eval "alg_executable=\$dp_$alg"

		if [ "$alg_executable" != "NO" ]; then
			$alg_executable "$file" >> "${DISTINFO_NEW}"
		fi
	done
	echo "SIZE ($file) = $(stat -f %z "$file")" >> "${DISTINFO_NEW}"
done

# Now, we generate the distinfo file in two cases:
# - If the saved file is empty, it means there was no TIMESTAMP in it, so we
#   need to add one.
# - If the old and new distinfo content minus the TIMESTAMP differ, it means
#   something was updated or changed, it is time to generate a new timestamp.
if [ ! -s ${DISTINFO_OLD} ] || ! cmp -s ${DISTINFO_OLD} ${DISTINFO_NEW}; then
	echo "TIMESTAMP = $(date '+%s')" > ${dp_DISTINFO_FILE}
	cat ${DISTINFO_NEW} >> ${dp_DISTINFO_FILE}
fi
