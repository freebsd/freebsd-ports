# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	twind
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Match and remove all of the blocks before time runs out

LICENSE=	GPLv2

USE_SDL=	sdl image mixer

PORTDOCS=	AUTHORS CREDITS ChangeLog NEWS README TODO

DESKTOP_ENTRIES="Twin Distress" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-DDATA_PREFIX=\"${DATADIR}/\" -DAUDIO -DLINUX \
		-lm `${SDL_CONFIG} --cflags --libs` -lSDL_mixer -lSDL_image twind.c
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "graphics music sound" ${DATADIR})

	${INSTALL_DATA} ${WRKSRC}/graphics/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
