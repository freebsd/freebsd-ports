#!/bin/sh
# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

set -e

. ${dp_SCRIPTSDIR}/functions.sh

recursive=0
requires_wrkdir=0
while getopts "rw" FLAG; do
	case "${FLAG}" in
		r)
			recursive=1
			;;
		w)
			# Only list dependencies that have a WRKDIR.  Used for
			# 'make clean-depends'.
			requires_wrkdir=1
			;;
		*)
			echo "Unknown flag" >&2
			exit 1
			;;
	esac
done
shift $((OPTIND-1))

validate_env PORTSDIR dp_PKGNAME
if [ ${recursive} -eq 1 -o ${requires_wrkdir} -eq 1 ]; then
	validate_env dp_MAKE
	# Cache command executions to avoid looking them up again in every
	# sub-make.
	MAKE="${dp_MAKE}" export_ports_env >/dev/null
fi

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_DEPENDS_LIST}" ] && set -x

set -u

check_dep() {
	local _dep wrkdir show_dep

	for _dep ; do
		myifs=${IFS}
		IFS=:
		set -- ${_dep}
		IFS=${myifs}

		case "${2}" in
			/*) d=${2} ;;
			*) d=${PORTSDIR}/${2} ;;
		esac

		case " ${checked} " in
			*\ ${d}\ *) continue ;; # Already checked
		esac
		checked="${checked} ${d}"
		# Check if the dependency actually exists or skip otherwise.
		if [ ! -d ${d} ]; then
			echo "${dp_PKGNAME}: \"${d}\" non-existent -- dependency list incomplete" >&2
			continue
		fi

		# Grab any needed vars from the port.

		if [ ${requires_wrkdir} -eq 1 -a ${recursive} -eq 1 ]; then
			set -- $(${dp_MAKE} -C ${d} -VWRKDIR -V_UNIFIED_DEPENDS)
			wrkdir="$1"
			shift
		elif [ ${requires_wrkdir} -eq 1 -a ${recursive} -eq 0 ]; then
			set -- "$(${dp_MAKE} -C ${d} -VWRKDIR)"
			wrkdir="$1"
		elif [ ${recursive} -eq 1 ]; then
			set -- $(${dp_MAKE} -C ${d} -V_UNIFIED_DEPENDS)
		fi

		# If a WRKDIR is required to show the dependency, check for it.
		show_dep=1
		if [ ${requires_wrkdir} -eq 1 ] && ! [ -d "${wrkdir}" ]; then
			show_dep=0
		fi
		[ ${show_dep} -eq 1 ] && echo ${d}
		if [ ${recursive} -eq 1 ]; then
			check_dep $@
		fi
	done
}

checked=
check_dep $@
