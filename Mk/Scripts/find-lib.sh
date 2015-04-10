#!/bin/sh
# MAINTAINER: portmgr@FreeBSD.org
# $FreeBSD$

if [ -z "${LIB_DIRS}" -o -z "${LOCALBASE}" ]; then
	echo "LIB_DIRS, LOCALBASE required in environment." >&2
	exit 1
fi

if [ $# -ne 1 ]; then
	echo "$0: no argument provided." >&2
fi

lib=$1
dirs="${LIB_DIRS} `cat ${LOCALBASE}/libdata/ldconfig/* 2>/dev/null || :`"

for libdir in ${dirs} ; do
	test -f ${libdir}/${lib} || continue
	libfile=${libdir}/${lib}
	[ `file -b -L --mime-type ${libfile}` = "application/x-sharedlib" ] || continue
	echo $libfile
	break
done
