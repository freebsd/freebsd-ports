#!/bin/sh
# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

# This script regenerates patches.  It conserves existing comments and
# file names, even if the file name does not meet any current or
# previous convention.  It will keep multiple patches in the same file
# rather than splitting them into individual files.
#
# If a generated patch was not present before, it will create a file
# name where forward slashes are replaced with an underscore and
# underscores are appended by another underscore.
#
# Limitations:
# 1) If a file is modified by multiple patches, it will be regenerated
#    as a single patch.  That means if two multi-patch files modified
#    the same source file, when regenerated, the source file's patch
#    will only appear in one of patch file.
# 2) It's possible that trailing garbage at the end of a patch in a
#    multipatch file might corrupt the comment (or be interpreted as
#    a comment) of the following patch.  (garbage in, garbage out)
#
# Reminder
# Don't forget to disable post-patch targets before regenerating patches
# if those targets modify source files (e.g. with sed).  You may also
# want to disable EXTRA_PATCHES as well if that is being used.

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_SMART_MAKEPATCH}" ] && set -x

if [ -z "${PATCHDIR}" -o -z "${PATCH_WRKSRC}" -o -z "${WRKDIR}" ]; then
	echo "WRKDIR, PATCHDIR, and PATCH_WRKSRC required in environment." >&2
	exit 1
fi

WORKAREA=${WRKDIR}/.makepatch-tmp
PATCHMAP=${WORKAREA}/pregen.map
COMMENTS=${WORKAREA}/comments
REGENNED=${WORKAREA}/regenerated
DESTDIR=${WORKAREA}/staged
SAVEDIR=${WORKAREA}/archived-patches

case "${STRIP_COMPONENTS}" in
	[123456789])	;;
	1[0123456789])	;;
	*)		STRIP_COMPONENTS=0
esac

strip_path() {
	local raw_name=$1
	if [ "${STRIP_COMPONENTS}" = "0" ]; then
		echo ${raw_name}
	else
		echo ${raw_name} | awk -v sc=${STRIP_COMPONENTS} -F "/" \
		'{ for (x = sc + 1; x <= NF; x++) { \
			slash = (x>sc+1) ? "/" : ""; \
			printf ("%s%s", slash, $x); \
		   }}'
	fi
}

std_patch_filename() {
	local sans_cwd
	local raw_name
	sans_cwd=$(echo $1 | sed 's|^\.\/||')
	raw_name=$(strip_path ${sans_cwd})
	echo patch-$(echo ${raw_name} | sed -e 's|_|&&|g; s|/|_|g')
}

patchdir_files_list() {
	if [ -d "${PATCHDIR}" ]; then
		(cd ${PATCHDIR} && \
			find * -type f -name "patch-*" -maxdepth 0 \
			2>/dev/null | sed -e '/\.orig$/d'
		)
	fi;
}

valid_name() {
	local current_patch_name=$1
	local result=$3
	local first_target
	local testres
	local lps
	first_target=$(echo $2 | sed 's|^\.\/||')
	for lps in __ - + ; do
		testres=patch-$(echo ${first_target} | sed -e "s|/|${lps}|g")
		if [ "${testres}" = "${current_patch_name}" ]; then
			result=${testres}
			break
		fi
	done
	echo ${result}
}

map_existing_patches() {
	mkdir -p ${WORKAREA}
	: > ${PATCHMAP}
	local target
	local future_name
	local std_target
	local P
	local t
	for P in ${old_patch_list}; do
		target=$(cd ${PATCHDIR} && \
			grep "^+++ " ${P} | awk '{print $2}'
		)
		# For single patches, we honor previous separators, but use
		# a standard patch name if the current patch name does not
		# conform.  However, if two or more patches are contained in
		# single file, then we do *NOT* rename the file
		future_name=
		for t in ${target}; do
			if [ -n "${future_name}" ]; then
				future_name=${P}
				break;
			fi
			std_target=$(std_patch_filename ${t})
			future_name=$(valid_name ${P} ${t} ${std_target})
		done
		for t in ${target}; do
			std_target=$(std_patch_filename ${t})
			echo "${future_name}	${std_target}" >> ${PATCHMAP}
		done
	done
}

extract_comment_from_patch() {
	local existing_patch=${PATCHDIR}/$1
	local contains
	local rawname
	local fname
	local num
	contains=$(grep "^+++ " ${existing_patch} | awk '{x++; print x}')
	for num in ${contains}; do
		rawname=$(grep "^+++ " ${existing_patch} | \
			awk -v num=${num} '{x++; if (x==num) print $2}')
		fname=$(std_patch_filename $rawname)
		awk -v num=${num} '\
		BEGIN { done=0; x=0; hunk=0; looking=(num==1) } \
		{ \
		    if (!done) { \
		        if ($1 == "@@") { \
		            split ($2,a,","); \
		            split ($3,b,","); \
		            hca = a[2];
		            hcb = a[3];
		            hunk = 1;
		        } else if (hunk) { \
		            first=substr($1,1,1); \
		            if (first == "-") { hca-- } \
		            else if (first == "+") { hcb-- } \
		            else {hca--; hcb--} \
		            if (hca == 0 && hcb == 0) {hunk = 0} \
		        } \
			if ($1 == "---") { \
			   x++; \
			   if (x == num) { done = 1 } \
			   if (x + 1 == num) { looking = 1 } \
			} else if (!hunk && looking) { \
		            if ($1!="diff" && $1!="index" && $1!="+++") {\
		                print $0 \
		            } \
		        } \
		    } \
		}' ${existing_patch} > ${COMMENTS}/${fname}
	done
}

extract_comments() {
	mkdir -p ${COMMENTS}
	rm -f ${COMMENTS}/*
	local P
	for P in ${old_patch_list}; do
		extract_comment_from_patch ${P}
	done
}

regenerate_patches() {
	mkdir -p ${REGENNED}
	rm -f ${REGENNED}/*
	[ ! -d "${PATCH_WRKSRC}" ] && return

	local F
	local NEW
	local OUT
	local ORIG
	local new_list
	new_list=$(cd "${PATCH_WRKSRC}" && \
		find -s * -type f -name '*.orig' 2>/dev/null)
	(cd "${PATCH_WRKSRC}" && for F in ${new_list}; do
		ORIG=${F#./}
		NEW=${ORIG%.orig}
		cmp -s ${ORIG} ${NEW} && continue
		OUT=${REGENNED}/$(std_patch_filename ${NEW})
		TZ=UTC diff -udp ${ORIG} ${NEW} | sed \
			-e '/^---/s|\.[0-9]* +0000$| UTC|' \
			-e '/^+++/s|\([[:blank:]][-0-9:.+]*\)*$||' \
			> ${OUT} || true
	done)
}

get_patch_name() {
	awk -v name=$1 '\
	{ if ($2 == name) \
	  { \
	      if (!done) { print $1 }; \
	      done = 1; \
	  } \
	} \
	END { if (!done) print name }' ${PATCHMAP}
}

stage_patches() {
	mkdir -p ${DESTDIR}
	rm -f ${DESTDIR}/*
	local P
	local name
	local patch_list
	patch_list=$(cd ${REGENNED} && find * -name "patch-*" 2>/dev/null)
	for P in ${patch_list}; do
		name=$(get_patch_name ${P})
		[ -e ${COMMENTS}/${P} ] && cat ${COMMENTS}/${P} \
			>> ${DESTDIR}/${name}
		if [ "${P}" = "${name}" ]; then
			echo "Generated ${P}"
		else
			echo "Generated ${P} >> ${name} (legacy)"
		fi
		cat ${REGENNED}/${P} >> ${DESTDIR}/${name}
	done
}

conserve_old_patches() {
	mkdir -p ${SAVEDIR}
	rm -f ${SAVEDIR}/*
	[ -z "${old_patch_list}" ] && return

	local P
	for P in ${old_patch_list}; do
		mv ${PATCHDIR}/${P} ${SAVEDIR}/${P}
	done
	echo "The previous patches have been placed here:"
	echo ${SAVEDIR}
}

install_regenerated_patches() {
	local testdir=$(find ${DESTDIR} -empty)
	if [ -z "${testdir}" ]; then
		mkdir -p ${PATCHDIR}
		find ${DESTDIR} -type f -exec mv {} ${PATCHDIR}/ \;
	fi
}

old_patch_list=$(patchdir_files_list)

map_existing_patches
extract_comments
regenerate_patches
stage_patches
conserve_old_patches
install_regenerated_patches
