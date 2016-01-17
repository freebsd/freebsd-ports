# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	puckman
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unofficial clone of the original Pac-Man game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	patapizza
GH_TAGNAME=	f5b809c

USES=		gmake
USE_SDL=	sdl image gfx

PORTDOCS=	README.md
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Puck-Man" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/puckman.c

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-DDATA_PREFIX=\"${DATADIR}/\" \
		-lm `${SDL_CONFIG} --cflags --libs` -lSDL -lSDL_image \
		-lSDL_gfx -lm puckman.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} images ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
