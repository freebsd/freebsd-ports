# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=		drm
PORTVERSION=		1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
DISTNAME=		dr_mario
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Very simple Tetris-style game

ALL_TARGET=

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bugs ${STAGEDIR}${PREFIX}/bin/drm
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
