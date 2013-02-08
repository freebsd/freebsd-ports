# Created by:   nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	tong
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.nongnu.org/tong/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Tetris and Pong in the same place at the same time

LICENSE=	GPLv3

USE_SDL=	image mixer sdl
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	CHANGELOG README making-of.txt notes.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

DESKTOP_ENTRIES="TONG!" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|GAME_DATA_DIR := .|GAME_DATA_DIR := ${DATADIR}|' \
	-e 's|CC = g++ -O3 |CC = ${CXX} ${CXXFLAGS} |' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "*.png" ${DATADIR}
	${MKDIR} ${DATADIR}/media
	@cd ${WRKSRC}/media && ${COPYTREE_SHARE} "*.png *.xcf *.ogg *.ico" ${DATADIR}/media
	${LN} -sf ${DATADIR}/media/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
