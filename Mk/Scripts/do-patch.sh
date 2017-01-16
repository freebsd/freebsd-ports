#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_BZCAT dp_CAT dp_DISTDIR dp_ECHO_MSG dp_EXTRA_PATCHES \
	dp_EXTRA_PATCH_TREE dp_GZCAT dp_OPSYS dp_PATCH dp_PATCHDIR \
	dp_PATCHFILES dp_PATCH_ARGS dp_PATCH_DEBUG_TMP dp_PATCH_DIST_ARGS \
	dp_PATCH_SILENT dp_PATCH_WRKSRC dp_PKGNAME dp_PKGORIGIN \
	dp_UNZIP_NATIVE_CMD dp_XZCAT

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_DO_PATCH}" ] && set -x

set -u

apply_one_patch() {
	local file="$1"
	local msg="$2"
	shift 2
	local patch_strip=""

	case ${file} in
		*:-p[0-9])
			patch_strip=${file##*:}
			file=${file%:-p[0-9]}
			;;
	esac

	if [ -n "${msg}" ]; then
		${dp_ECHO_MSG} "===>  ${msg} ${file}${patch_strip:+ with ${patch_strip}}"
	fi

	case "${file}" in
		*.Z|*.gz)
			${dp_GZCAT} "${file}"
			;;
		*.bz2)
			${dp_BZCAT} "${file}"
			;;
		*.xz)
			${dp_XZCAT} "${file}"
			;;
		*.zip)
			${dp_UNZIP_NATIVE_CMD} -p "${file}"
			;;
		*)
			${dp_CAT} "${file}"
			;;
	esac | do_patch "$@" ${patch_strip}
}

do_patch() {
	"${dp_PATCH}" -d "${dp_PATCH_WRKSRC}" "$@"
}

patch_from_directory() {
	local dir="$1"
	local msg="$2"

	if [ -d "${dir}" ]; then
		cd "${dir}"

		if [ "$(echo patch-*)" != "patch-*" ]; then

			${dp_ECHO_MSG} "===>  Applying ${msg} patches for ${dp_PKGNAME}"

			PATCHES_APPLIED=""

			for i in patch-*; do
				case ${i} in
					*.orig|*.rej|*~|*,v)
						${dp_ECHO_MSG} "===>   Ignoring patchfile ${i}"
						;;
					*)
						if [ -n "${dp_PATCH_DEBUG_TMP}" ]; then
							${dp_ECHO_MSG} "===>  Applying ${msg} patch ${i}"
						fi
						if do_patch ${dp_PATCH_ARGS} < ${i}; then
							PATCHES_APPLIED="${PATCHES_APPLIED} ${i}"
						else
							${dp_ECHO_MSG} "=> ${msg} patch ${i} failed to apply cleanly."
							if [ -n "${PATCHES_APPLIED}" -a "${dp_PATCH_SILENT}" != "yes" ]; then
								${dp_ECHO_MSG} "=> Patch(es) ${PATCHES_APPLIED} applied cleanly."
							fi
							false
						fi
						;;
				esac
			done
		fi
	fi
}

if [ -n "${dp_PATCHFILES}" ]; then
	${dp_ECHO_MSG} "===>  Applying distribution patches for ${dp_PKGNAME}"
	cd "${dp_DISTDIR}"
	for i in ${dp_PATCHFILES}; do
		apply_one_patch "${i}" \
			"${dp_PATCH_DEBUG_TMP:+ Applying distribution patch}" \
			${dp_PATCH_DIST_ARGS}
	done
fi

if [ -n "${dp_EXTRA_PATCHES}" ]; then
	for i in ${dp_EXTRA_PATCHES}; do
		apply_one_patch "${i}" \
			"Applying extra patch" \
			${dp_PATCH_ARGS}
	done
fi

patch_from_directory "${dp_PATCHDIR}" "${dp_OPSYS}"

