#!/bin/sh
# $FreeBSD$

if [ -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc ]; then
	exit
fi

exec > ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc

echo "MAN3=	\\"
find ${WRKDIRPREFIX}${REALCURDIR}/work/${DISTNAME}/doc/MFS/man3 -type f -exec basename {} \; | sed 's,$, \\,'

echo
echo "MLINKS= \\"
ls -al ${WRKDIRPREFIX}${REALCURDIR}/work/${DISTNAME}/doc/MFS/man3 | \
	awk '/->/ { print $(NF), $(NF - 2), " \\" }'
echo
