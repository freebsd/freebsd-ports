# ex:ts=8
# Ports collection makefile for:  raidtest
# Date created:			  Sat Oct 16, 2004
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	raidtest
PORTVERSION=	1.0
CATEGORIES=	benchmarks

MAINTAINER=	pjd@FreeBSD.org
COMMENT=	used to test performance of storage devices

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/raidtest

do-fetch:

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf ${FILESDIR}/${PORTNAME}.c ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
