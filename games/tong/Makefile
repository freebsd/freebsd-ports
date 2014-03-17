# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tong
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.nongnu.org/tong/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Tetris and Pong in the same place at the same time

LICENSE=	GPLv3

USES=		gmake
USE_SDL=	image mixer sdl

PORTDOCS=	CHANGELOG README making-of.txt notes.txt
OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}

DESKTOP_ENTRIES="TONG!" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|GAME_DATA_DIR := .|GAME_DATA_DIR := ${DATADIR}|' \
	-e 's|CC = g++ -O3 |CC = ${CXX} ${CXXFLAGS} |' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "*.png" ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DATADIR}/media/
.for f in *.png *.xcf *.ogg *.ico
	@(cd ${WRKSRC}/media && ${COPYTREE_SHARE} "${f}" ${STAGEDIR}${DATADIR}/media/)
.endfor

	${LN} -sf ${DATADIR}/media/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
