#!/bin/sh
# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

set -e

. ${dp_SCRIPTSDIR}/functions.sh

validate_env dp_ALLDEPENDS dp_PORTSDIR dp_PKGNAME

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
	done
}

checked=
check_dep ${dp_ALLDEPENDS}
