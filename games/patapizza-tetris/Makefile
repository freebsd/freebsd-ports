# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	patapizza-tetris
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unofficial clone of the original Tetris game

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	patapizza
GH_PROJECT=	tetris
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	e6f1a41

USES=		gmake
USE_SDL=	sdl image gfx ttf

PORTDOCS=	README.md
OPTIONS_DEFINE=	DOCS

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Patapizza Tetris" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|CC =|CC ?=|; \
		s|/usr|${PREFIX}|' ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-DDATA_PREFIX=\"${DATADIR}/\" \
		-lm `${SDL_CONFIG} --cflags --libs` -lSDL -lSDL_image \
		-lSDL_gfx -lSDL_ttf -lm tetris.c

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} images ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
