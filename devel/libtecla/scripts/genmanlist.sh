#!/bin/sh
# $FreeBSD: /tmp/pcvs/ports/devel/libtecla/scripts/genmanlist.sh,v 1.1 2004-07-18 10:06:01 sem Exp $

if [ -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc ]; then
	exit
fi

exec > ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc

cd ${WRKDIRPREFIX}${REALCURDIR}/work/${PORTNAME}/man
echo "MAN3=	\\"
for n in libr/*.in; do
	page=`basename "$n" .in`;
	echo "$page.3 \\"
done
for n in func/*.in; do
	page=`basename "$n" .in`;
	echo "$page.3 \\"
done
echo
echo "MAN1=	\\"
for n in prog/*.in; do
	page=`basename "$n" .in`;
	echo "$page.1 \\"
done
echo
echo "MAN5=	\\"
for n in file/*.in; do
	page=`basename "$n" .in`;
	echo "$page.5 \\"
done
echo
echo "MAN7=	\\"
for n in misc/*.in; do
	page=`basename "$n" .in`;
	echo "$page.7 \\"
done
echo
