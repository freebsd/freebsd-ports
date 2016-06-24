#!/bin/sh
# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org

set -e

. ${dp_SCRIPTSDIR}/functions.sh

validate_env dp_RAWDEPENDS dp_DEPTYPE dp_DEPENDS_TARGET dp_DEPENDS_PRECLEAN \
	dp_DEPENDS_CLEAN dp_DEPENDS_ARGS dp_USE_PACKAGE_DEPENDS \
	dp_USE_PACKAGE_DEPENDS_ONLY dp_PKG_ADD dp_PKG_INFO dp_WRKDIR \
	dp_PKGNAME dp_STRICT_DEPENDS dp_LOCALBASE dp_LIB_DIRS dp_SH \
	dp_SCRIPTSDIR PORTSDIR dp_MAKE

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_DO_DEPENDS}" ] && set -x

set -u

install_depends()
{
	origin=$1
	target=$2
	depends_args=$3
	if [ -z "${dp_USE_PACKAGE_DEPENDS}" -a -z "${dp_USE_PACKAGE_DEPENDS_ONLY}" ]; then
		${dp_MAKE} -C ${origin} -DINSTALLS_DEPENDS ${target} ${depends_args}
		return 0
	fi

	port_var_fetch "${origin}" "${depends_args}" \
	    PKGFILE pkgfile \
	    PKGBASE pkgbase

	if [ -r "${pkgfile}" -a "${target}" = "${dp_DEPENDS_TARGET}" ]; then
		echo "===>   Installing existing package ${pkgfile}"
		if [ "${pkgbase}" = "pkg" ]; then
			[ -d ${dp_WRKDIR} ] || mkdir -p ${dp_WRKDIR}
			tar xf ${pkgfile} -C ${dp_WRKDIR} -s ",/.*/,,g" "*/pkg-static"
			${dp_WRKDIR}/pkg-static add ${pkgfile}
			rm -f ${dp_WRKDIR}/pkg-static
		else
			${dp_PKG_ADD} -A ${pkgfile}
		fi
	elif [ -n "${dp_USE_PACKAGE_DEPENDS_ONLY}" -a "${target}" = "${dp_DEPENDS_TARGET}" ]; then
		echo "===>   ${dp_PKGNAME} depends on package: ${pkgfile} - not found" >&2
		echo "===>   USE_PACKAGE_DEPENDS_ONLY set - not building missing dependency from source" >&2
		exit 1
	else
		${dp_MAKE} -C ${origin} -DINSTALLS_DEPENDS ${target} ${depends_args}
	fi
}

find_package()
{
	if ${dp_PKG_INFO} "$1" >/dev/null 2>&1; then
		echo "===>   ${dp_PKGNAME} depends on package: $1 - found"
		return 0
	fi
	echo "===>   ${dp_PKGNAME} depends on package: $1 - not found"
	return 1
}

find_file()
{
	if [ -e "$1" ]; then
		echo "===>   ${dp_PKGNAME} depends on file: $1 - found"
		return 0
	fi
	echo "===>   ${dp_PKGNAME} depends on file: $1 - not found"
	return 1
}

find_file_path()
{
	if which -s $1 ; then
		echo "===>   ${dp_PKGNAME} depends on executable: $1 - found"
		return 0
	fi
	echo "===>   ${dp_PKGNAME} depends on executable: $1 - not found"
	return 1
}

find_lib()
{
	echo -n "===>   ${dp_PKGNAME} depends on shared library: $1"
	libfile=$(env -i PATH="${PATH}" LIB_DIRS="${dp_LIB_DIRS}" LOCALBASE="${dp_LOCALBASE}" ${dp_SH} ${dp_SCRIPTSDIR}/find-lib.sh $1)
	if [ -z "${libfile}" ]; then
		echo " - not found"
		return 1
	fi
	echo " - found (${libfile})"
}

anynotfound=0
err=0
for _line in ${dp_RAWDEPENDS} ; do
	myifs=${IFS}
	IFS=:
	set -- ${_line}
	IFS=${myifs}
	if [ $# -lt 2 -o $# -gt 3 ]; then
		echo "Error: bad dependency syntax in ${dp_DEPTYPE}" >&2
		echo "expecting: pattern:origin[:target]" >&2
		echo "got: ${_line}" >&2
		err=1
		continue
	fi
	pattern=$1
	origin=$2
	last=${3:-}

	if [ -z "${pattern}" ]; then
		echo "Error: there is an empty port dependency in ${dp_DEPTYPE}" >&2
		err=1
		continue
	fi

	if [ -z "${origin}" ]; then
		echo "Error: a dependency has an empty origin in ${dp_DEPTYPE}" >&2
		err=1
		continue
	fi

	case "${origin}" in
	/*) ;;
	*) origin="${PORTSDIR}/${origin}" ;;
	esac

	depends_args="${dp_DEPENDS_ARGS}"
	target=${dp_DEPENDS_TARGET}
	if [ -n "${last}" ]; then
		target=${last}
		if [ -n "${dp_DEPENDS_PRECLEAN}" ]; then
			target="clean ${target}"
			depends_args="NOCLEANDEPENDS=yes"
		fi
		if [ -n "${dp_DEPENDS_CLEAN}" ]; then
			target="${target} clean"
			depends_args="NOCLEANDEPENDS=yes"
		fi
	fi

	case ${dp_DEPTYPE} in
	  LIB_DEPENDS)
	    case ${pattern} in
	      lib*.so*)      fct=find_lib ;;
	      *)
		echo "Error: pattern ${pattern} in LIB_DEPENDS is not valid"
		err=1
		continue
		;;
	    esac ;;
	  *)
	    case ${pattern} in
	      *\>*|*\<*|*=*) fct=find_package ;;
	      /nonexistent)  fct=false ;;
	      /*)            fct=find_file ;;
	      *)             fct=find_file_path ;;
	    esac ;;
	esac
	if ${fct} "${pattern}" ; then
		continue
	fi
	[ ${pattern} = "/nonexistent" ] || anynotfound=1

	if [ ! -f "${origin}/Makefile" ]; then
		echo "Error a dependency refers to a non existing origin: ${origin} in ${dp_DEPTYPE}" >&2
		err=1
		continue
	fi

	# Now actually install the dependencies
	install_depends "${origin}" "${target}" "${depends_args}"
	# Recheck if the installed dependency validates the pattern except for /nonexistent
	[ "${fct}" = "false" ] || ${fct} "${pattern}"
	echo "===>   Returning to build of ${dp_PKGNAME}"
done

if [ $err -eq 1 ]; then
	echo "Errors with dependencies."
	exit 1
fi

if [ -n "${dp_STRICT_DEPENDS}" -a ${anynotfound} -eq 1 ]; then \
	echo "===>   dp_STRICT_DEPENDS set - Not installing missing dependencies."
	echo "       This means a dependency is wrong since it was not satisfied in the ${dp_DEPTYPE} phase."
	exit 1
fi
