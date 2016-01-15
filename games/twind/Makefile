# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twind
PORTVERSION=	1.1.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Match and remove all of the blocks before time runs out

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_SDL=	sdl image mixer

PORTDOCS=	AUTHORS CREDITS ChangeLog NEWS README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Twin Distress" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-DDATA_PREFIX=\"${DATADIR}/\" -DAUDIO -DLINUX \
		-lm `${SDL_CONFIG} --cflags --libs` -lSDL_mixer -lSDL_image twind.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "graphics music sound" ${STAGEDIR}${DATADIR})

	${INSTALL_DATA} ${WRKSRC}/graphics/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
