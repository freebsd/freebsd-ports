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
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pjd@FreeBSD.org
COMMENT=	Test performance of storage devices

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501000
IGNORE=		supports only FreeBSD 5.1 and above
.endif

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/raidtest

do-fetch:

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf ${FILESDIR}/${PORTNAME}.c ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.post.mk>
