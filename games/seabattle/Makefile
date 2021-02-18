# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	seabattle
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy/ \
		http://www.deater.net/weave/vmwprod/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based battleship type game

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: current_player
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: current_player

USES=		ncurses

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/seabattle ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/seabattle
	${INSTALL_DATA} ${WRKSRC}/*.au ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
