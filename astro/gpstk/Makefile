# New ports collection makefile for:	gpstk
# Date created:				12 May 2004
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		gpstk
PORTVERSION=		1.3
CATEGORIES=		astro devel
MASTER_SITES=		SF
DISTNAME=		${PORTNAME}${PORTVERSION}.src

MAINTAINER=		bms@FreeBSD.org
COMMENT=		Toolkit for developing GPS applications

BUILD_DEPENDS=		${LOCALBASE}/bin/jam:${PORTSDIR}/devel/jam

USE_LDCONFIG=		yes

WRKSRC=			${WRKDIR}/${PORTNAME}
JAM=			${LOCALBASE}/bin/jam
JAM_ENV=		BINDIR=${PREFIX}/bin \
			INCDIR=${PREFIX}/include/$(PORTNAME) \
			LIBDIR=${PREFIX}/lib \
			CC=${CC} C++=${CXX}

do-build:
	cd ${WRKSRC} && ${SETENV} ${JAM_ENV} ${JAM}

do-install:
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${SETENV} ${JAM_ENV} ${JAM} install

.include <bsd.port.mk>
