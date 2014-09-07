# Created by: David O'Brien (obrien@FreeBSD.org)
# $FreeBSD$

PORTNAME=	raidtest
PORTVERSION=	1.3
CATEGORIES=	benchmarks
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pjd@FreeBSD.org
COMMENT=	Test performance of storage devices

NO_WRKSUBDIR=	yes
USES=		uidfix
PLIST_FILES=	bin/raidtest

do-fetch:

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf ${FILESDIR}/${PORTNAME}.c ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
