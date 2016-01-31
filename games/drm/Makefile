# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	drm
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade
DISTNAME=	dr_mario

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very simple Tetris-style game

ALL_TARGET=	bugs
USES=		ncurses tar:Z

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bugs ${STAGEDIR}${PREFIX}/bin/drm
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
