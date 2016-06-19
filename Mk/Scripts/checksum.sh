#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_CHECKSUM_ALGORITHMS dp_CURDIR dp_DISTDIR dp_DISTINFO_FILE \
	dp_DIST_SUBDIR dp_ECHO_MSG dp_FETCH_REGET dp_MAKE dp_MAKEFLAGS \
	dp_DISABLE_SIZE dp_NO_CHECKSUM

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_CHECKSUM}" ] && set -x

set -u

check_checksum_algorithms

if [ -f "${dp_DISTINFO_FILE}" ]; then
	cd "${dp_DISTDIR}"
	OK=
	refetchlist=
	for file in "${@}"; do
		ignored="true"
		for alg in ${dp_CHECKSUM_ALGORITHMS}; do
			ignore="false"
			eval "alg_executable=\$dp_${alg}"

			if [ "$alg_executable" != "NO" ]; then
				MKSUM=$($alg_executable < "${file}")
				CKSUM=$(distinfo_data "${alg}" "${file}")
			else
				ignore="true"
			fi

			if [ $ignore = "false" -a -z "$CKSUM" ]; then
				${dp_ECHO_MSG} "=> No $alg checksum recorded for $file."
				ignore="true"
			fi

			if [ $ignore != "false" ]; then
				continue
			fi

			match="false"
			for chksum in $CKSUM; do
				if [ "$chksum" = "$MKSUM" ]; then
					match="true"
					break
				fi
			done
			if [ $match = "true" ]; then
				${dp_ECHO_MSG} "=> $alg Checksum OK for $file."
				ignored="false"
			else
				${dp_ECHO_MSG} "=> $alg Checksum mismatch for $file."
				refetchlist="$refetchlist $file "
				OK="${OK:-retry}"
				[ "${OK}" = "retry" -a "${dp_FETCH_REGET}" -gt 0 ] && rm -f "${file}"
				ignored="false"
			fi
		done

		if [ $ignored = "true" ]; then
			${dp_ECHO_MSG} "=> No suitable checksum found for $file."
			OK=false
		fi
	done

	if [ "${OK:=true}" = "retry" ] && [ "${dp_FETCH_REGET}" -gt 0 ]; then
		${dp_ECHO_MSG} "===>  Refetch for ${dp_FETCH_REGET} more times files: $refetchlist"
		if ${dp_MAKE} -C "${dp_CURDIR}" ${dp_MAKEFLAGS} FORCE_FETCH_LIST="$refetchlist" FETCH_REGET="$((dp_FETCH_REGET - 1))" fetch; then
			if ${dp_MAKE} -C "${dp_CURDIR}" ${dp_MAKEFLAGS} FETCH_REGET="$((dp_FETCH_REGET - 1))" checksum ; then
			OK="true"
			fi
		fi
	fi

	if [ "$OK" != "true" -a "${dp_FETCH_REGET}" -eq 0 ]; then
		${dp_ECHO_MSG} "===>  Giving up on fetching files: $refetchlist"
		${dp_ECHO_MSG} "Make sure the Makefile and distinfo file (${dp_DISTINFO_FILE})"
		${dp_ECHO_MSG} "are up to date.  If you are absolutely sure you want to override this"
		${dp_ECHO_MSG} "check, type \"make NO_CHECKSUM=yes [other args]\"."
		exit 1
	fi
	if [ "$OK" != "true" ]; then
		exit 1
	fi
elif [ -n "${@}" ]; then
	${dp_ECHO_MSG} "=> No checksum file (${DISTINFO_FILE})."
	exit 1
fi
