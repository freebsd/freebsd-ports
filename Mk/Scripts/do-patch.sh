#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e
set -o pipefail

. "${dp_SCRIPTSDIR}/functions.sh"

validate_env dp_BZCAT dp_CAT dp_DISTDIR dp_ECHO_MSG dp_EXTRA_PATCHES \
	dp_EXTRA_PATCH_TREE dp_GZCAT dp_OPSYS dp_PATCH dp_PATCHDIR \
	dp_PATCHFILES dp_PATCH_ARGS dp_PATCH_DEBUG_TMP dp_PATCH_DIST_ARGS \
	dp_PATCH_SILENT dp_PATCH_WRKSRC dp_PKGNAME dp_PKGORIGIN \
	dp_UNZIP_NATIVE_CMD dp_XZCAT

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_DO_PATCH}" ] && set -x

set -u

has_failed=""

cat_file() {
	case "$1" in
		*.Z|*.gz)
			${dp_GZCAT} "$1"
			;;
		*.bz2)
			${dp_BZCAT} "$1"
			;;
		*.xz)
			${dp_XZCAT} "$1"
			;;
		*.zip)
			${dp_UNZIP_NATIVE_CMD} -p "$1"
			;;
		*)
			${dp_CAT} "$1"
			;;
	esac
}

# If we want to continue when one patch fails, set the flag, otherwise, abort.
if [ -n "${dp_PATCH_CONTINUE_ON_FAIL}" ]; then
	failure_fatal() {
		has_failed=1
	}
else
	failure_fatal() {
		false
	}
fi

apply_one_patch() {
	local file="$1"
	local msg="$2"
	local verbose="$3"
	shift 3
	local patch_strip=""

	case ${file} in
		*:-p[0-9])
			patch_strip=${file##*:}
			file=${file%:-p[0-9]}
			;;
	esac

	if [ -n "${verbose}" -o -n "${dp_PATCH_DEBUG_TMP}" ]; then
		${dp_ECHO_MSG} "===>  Applying ${msg} ${file}${patch_strip:+ with ${patch_strip}}"
	fi

	if ! cat_file "$file" | do_patch "$@" ${patch_strip}; then
		${dp_ECHO_MSG} "===>  FAILED Applying ${msg} ${file}${patch_strip:+ with ${patch_strip}}"
		false
	fi
}

do_patch() {
	"${dp_PATCH}" -d "${dp_PATCH_WRKSRC}" "$@"
}

patch_from_directory() {
	local dir="$1"
	local msg="$2"
	local patches_applied=""
	local patches_failed=""

	if [ -d "${dir}" ]; then
		cd "${dir}"

		if [ "$(echo patch-*)" != "patch-*" ]; then

			${dp_ECHO_MSG} "===>  Applying ${msg} patches for ${dp_PKGNAME} from ${dir}"


			for i in patch-*; do
				case ${i} in
					*.orig|*.rej|*~|*,v)
						${dp_ECHO_MSG} "====>   IGNORING patchfile ${i}"
						;;
					*)
						if apply_one_patch "${i}" "${msg}" "" ${dp_PATCH_ARGS}; then
							patches_applied="${patches_applied} ${i}"
						else
							patches_failed="${patches_failed} ${i}"
							if ! failure_fatal; then
								break
							fi
						fi
						;;
				esac
			done

			if [ -n "${patches_failed}" -a "${dp_PATCH_SILENT}" != "yes" ]; then
				if [ -n "${patches_applied}" ]; then
					${dp_ECHO_MSG} "===> Cleanly applied ${msg} patch(es) ${patches_applied}"
				fi
				${dp_ECHO_MSG} "===> FAILED to apply cleanly ${msg} patch(es) ${patches_failed}"
				# If we want to stop after the first failure, this returns false,
				# let its return value bubble up here and stop everything.
				failure_fatal
			fi
		fi
	fi
}

if [ -n "${dp_PATCHFILES}" ]; then
	${dp_ECHO_MSG} "===>  Applying distribution patches for ${dp_PKGNAME}"
	cd "${dp_DISTDIR}"
	for i in ${dp_PATCHFILES}; do
		if ! apply_one_patch "${i}" \
			"distribution patch" \
			"" \
			${dp_PATCH_DIST_ARGS}; then
			failure_fatal
		fi
	done
fi

if [ -n "${dp_EXTRA_PATCHES}" ]; then
	for i in ${dp_EXTRA_PATCHES}; do
		if [ -d "${i}" ]; then
			patch_from_directory "${i}" \
				"extra patch"
		else
			if ! apply_one_patch "${i}" \
				"extra patch" \
				"verbose" \
				${dp_PATCH_ARGS}; then
				failure_fatal
			fi
		fi
	done
fi

patch_from_directory "${dp_PATCHDIR}" "${dp_OPSYS}"

if [ -n "${dp_EXTRA_PATCH_TREE}" ]; then
	patch_from_directory "${dp_EXTRA_PATCH_TREE}/${dp_PKGORIGIN}" "local"
fi

if [ -n "$has_failed" ]; then
	if [ -n "${dp_PATCH_DEBUG_TMP}" ]; then
		${dp_ECHO_MSG} "==> Some patches failed to apply cleanly."
		${dp_ECHO_MSG} "==> Look for FAILED messages above."
	fi
	false
fi

