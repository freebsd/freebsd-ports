#!/bin/sh
# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

set -e

. ${dp_SCRIPTSDIR}/functions.sh

recursive=0
while getopts "r" FLAG; do
	case "${FLAG}" in
		r)
			recursive=1
			;;
		*)
			echo "Unknown flag" >&2
			exit 1
			;;
	esac
done
shift $((OPTIND-1))

validate_env dp_ALLDEPENDS dp_PORTSDIR dp_PKGNAME
[ ${recursive} -eq 1 ] && validate_env dp_MAKE

MAKE="${dp_MAKE}" PORTSDIR="${dp_PORTSDIR}" export_ports_env >/dev/null

set -u

check_dep() {
	for _dep ; do
		myifs=${IFS}
		IFS=:
		set -- ${_dep}
		IFS=${myifs}

		case "${2}" in
			/*) d=${2} ;;
			*) d=${dp_PORTSDIR}/${2} ;;
		esac

		case " ${checked} " in
			*\ ${d}\ *) continue ;; # Already checked
		esac
		checked="${checked} ${d}"
		if [ ! -d ${d} ]; then
			echo "${dp_PKGNAME}: \"${d}\" non-existent -- dependency list incomplete" >&2
			continue
		fi
		echo ${d}
		if [ ${recursive} -eq 1 ]; then
			check_dep $(${dp_MAKE} -C ${d} -V_UNIFIED_DEPENDS)
		fi
	done
}

checked=
check_dep ${dp_ALLDEPENDS}
