#!/bin/sh
# $FreeBSD$

if [ -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc ]; then
	exit
fi

${MKDIR} ${WRKDIRPREFIX}${REALCURDIR}
exec > ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc

cd ${WRKDIRPREFIX}${REALCURDIR}/work/${PORTNAME}/man3
echo "MAN3=	\\"
#echo *.3
ls *.3 | sed 's,$,\\,'
echo
