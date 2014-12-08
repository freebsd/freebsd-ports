# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_scavenger
PORTVERSION=	145.2014.01.01
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/sdlscavenger/
DISTNAME=	sdlscav-145_2014_01_01

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Lode Runner like game

LICENSE=	GPLv1

WRKSRC=		${WRKDIR}/sdlscav-145

USES=		gmake shebangfix tar:tgz
SHEBANG_FILES=	scavsaver
bash_CMD=	/bin/sh
USE_SDL=	sdl image mixer
USE_GCC=	yes
ALL_TARGET=

PORTDOCS=	CREDITS DOC NEW_FEATURES README STRATEGY

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="SDL Scavenger" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/scavenger|${DATADIR}|; \
		s|".scavenger"|".sdlscavenger"|' \
		${WRKSRC}/names.h
	@${REINPLACE_CMD} -e 's|sdlscav|sdl_scavenger|' ${WRKSRC}/scavsaver

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdlscav ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/data/scav.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
