# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	drm
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade
DISTNAME=	dr_mario

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very simple Tetris-style game

ALL_TARGET=	bugs
USES=		ncurses tar:Z

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bugs ${STAGEDIR}${PREFIX}/bin/drm
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
