# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	seabattle
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SUNSITE \
		http://www.deater.net/weave/vmwprod/
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based battleship type game

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/seabattle ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/seabattle
	${INSTALL_DATA} ${WRKSRC}/*.au ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
