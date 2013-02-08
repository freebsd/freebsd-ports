# $FreeBSD$

PORTNAME=	sdl_scavenger
PORTVERSION=	145.1.2010.11.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/sdlscavenger/
DISTNAME=	sdlscav-145.1_2010_11_5

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Lode Runner like game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/sdlscav-145

USE_ZIP=	yes
USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
ALL_TARGET=

PLIST_FILES=	bin/sdlscavenger \
		share/pixmaps/sdlscavenger.png

PORTDATA=	*
PORTDOCS=	CREDITS DOC NEW_FEATURES README STRATEGY

DESKTOP_ENTRIES="SDL Scavenger" "${COMMENT}" "sdlscavenger" \
		"sdlscavenger" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

post-patch:
		@${REINPLACE_CMD} -e 's|data:/usr/local/games/scavenger|data:${DATADIR}/data|' \
			${WRKSRC}/names.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdlscav ${PREFIX}/bin/sdlscavenger
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/data/scav.png ${PREFIX}/share/pixmaps/sdlscavenger.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
