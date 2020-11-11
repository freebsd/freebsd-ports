#!/bin/sh
# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

set -e
set -o pipefail

. ${dp_SCRIPTSDIR}/functions.sh

flavors=0
recursive=0
missing=0
requires_wrkdir=0
while getopts "fmrw" FLAG; do
	case "${FLAG}" in
		f)
			flavors=1
			;;
		m)
			missing=1
			recursive=1
			;;
		r)
			recursive=1
			;;
		w)
			# Only list dependencies that have a WRKDIR.  Used for
			# 'make clean-depends'.
			# Without -r recurse when WRKDIR exists; with -r
			# always recurse.
			requires_wrkdir=1
			;;
		*)
			echo "Unknown flag" >&2
			exit 1
			;;
	esac
done
shift $((OPTIND-1))

validate_env PORTSDIR dp_OVERLAYS dp_PKGNAME
if [ ${recursive} -eq 1 -o ${requires_wrkdir} -eq 1 ]; then
	validate_env dp_MAKE
	# Cache command executions to avoid looking them up again in every
	# sub-make.
	MAKE="${dp_MAKE}" export_ports_env >/dev/null
fi

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_DEPENDS_LIST}" ] && set -x

set -u

if [ ${missing} -eq 1 ]; then
	existing=$(${dp_PKG_INFO} -aoq|paste -d ' ' -s -)
fi

check_dep() {
	local _dep wrkdir show_dep

	for _dep ; do
		unset FLAVOR
		myifs=${IFS}
		IFS=:
		set -- ${_dep}
		IFS=${myifs}

		case "${2}" in
		/*) d=${2} ;;
		*) for overlay in ${dp_OVERLAYS} ${PORTSDIR}; do
			d=${overlay}/${2}
			f=
			case "${d}" in
			*@*/*) ;; # Ignore @ in the path which would not be a flavor
			*@*)
				f=${d##*@}
				d=${d%@*}
				;;
			esac
			if [ -f ${d}/Makefile ]; then
				if [ -n $f ]; then
					export FLAVOR=$f
				fi
				break
			fi
		done
		esac

		if [ ${flavors} -eq 1 -a -n "${FLAVOR:-}" ]; then
			port_display="${d}@${FLAVOR}"
		else
			port_display="${d}"
		fi

		case " ${checked} " in
			*\ ${d}\ *) continue ;; # Already checked
		esac
		checked="${checked} ${d}"
		# Check if the dependency actually exists or skip otherwise.
		if [ ! -d "${d}" ]; then
			echo "${dp_PKGNAME}: \"${port_display}\" non-existent -- dependency list incomplete" >&2
			continue
		fi

		# If only looking for missing, show if missing
		if [ ${missing} -eq 1 ]; then
			case " ${existing} " in
				*\ ${d#${PORTSDIR}/}\ *) continue ;; # We have it, nothing to see
			esac
		fi

		# Grab any needed vars from the port.

		if [ ${requires_wrkdir} -eq 1 ]; then
			# shellcheck disable=SC2046
			# We want word splitting here.
			set -- $(${dp_MAKE} -C ${d} -VWRKDIR -V_UNIFIED_DEPENDS)
			wrkdir="$1"
			shift
		elif [ ${recursive} -eq 1 ]; then
			# shellcheck disable=SC2046
			# We want word splitting here.
			set -- $(${dp_MAKE} -C ${d} -V_UNIFIED_DEPENDS)
		fi

		# If a WRKDIR is required to show the dependency, check for it.
		show_dep=1
		if [ ${requires_wrkdir} -eq 1 ] && ! [ -d "${wrkdir}" ]; then
			show_dep=0
		fi
		[ ${show_dep} -eq 1 ] && echo "${port_display}"
		if [ ${recursive} -eq 1 -o ${requires_wrkdir} -eq 1 -a ${show_dep} -eq 1 ]; then
			# shellcheck disable=SC2068
			# Do not add quotes, we want to split the string here.
			check_dep $@
		fi
	done
}

checked=
# shellcheck disable=SC2068
# Do not add quotes, we want to split the string here.
check_dep $@
