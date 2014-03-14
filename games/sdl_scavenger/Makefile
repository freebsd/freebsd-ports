# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_scavenger
PORTVERSION=	145.2014.01.01
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/sdlscavenger/
DISTNAME=	sdlscav-145_2014_01_01
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Lode Runner like game

LICENSE=	GPLv1

WRKSRC=		${WRKDIR}/sdlscav-145

USES=		gmake
USE_SDL=	sdl image mixer
USE_GCC=	yes
ALL_TARGET=

PORTDOCS=	CREDITS DOC NEW_FEATURES README STRATEGY

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="SDL Scavenger" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/scavenger|${DATADIR}/data|' \
		${WRKSRC}/names.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdlscav ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})
	${LN} -sf ${DATADIR}/data/scav.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
