# New ports collection makefile for:	xworm
# Date created:				18 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xworm
PORTVERSION=	1.02
CATEGORIES=	games
MASTER_SITES=	http://www.ekran.no/archive/x/
DISTNAME=	xworm102

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	freebsd
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/XWorm

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xworm ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xworm
.for file in font grid raw
	@ ${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${PREFIX}/share/xworm
.endfor

.include <bsd.port.mk>
