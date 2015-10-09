#!/bin/sh
# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

. ${dp_SCRIPTSDIR}/functions.sh

set -e
validate_env dp_PKGNAME dp_MAKE dp_PORTSDIR

arg=$1
if [ -z "${arg}" ] || [ "${arg}" != "full" -a "${arg}" != "limited" ]; then
	echo "The first argument can only be 'full' or 'limited'" >&2
	exit 1
fi
shift

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
		set -- $(${dp_MAKE} -C ${d} -VWRKDIR -V_UNIFIED_DEPENDS)
		if [ -d ${1} ]; then
			echo ${d}
		elif [ "$arg" = "limited" ]; then
			continue
		fi
		shift
		check_dep $@
	done
}

checked=
check_dep ${dp_ALLDEPENDS}
