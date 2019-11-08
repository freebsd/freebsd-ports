# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_lopan
PORTVERSION=	10
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/sdllopan/downloads/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	sdllopan-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	sdllopan-${DISTVERSION}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mahjong game remake

WRKSRC=		${WRKDIR}/sdllopan-${PORTVERSION}

USES=		gmake sdl
USE_SDL=	sdl image mixer
ALL_TARGET=	# empty

PORTDOCS=	Changelog README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="SDL Lopan" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;BoardGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|data/bg%d.pcx|${DATADIR}/data/bg%d.pcx| ; \
	s|data/tiles%d.pcx|${DATADIR}/data/tiles%d.pcx| ; \
	s|char temp\[64\];|char temp\[256\];|' \
		${WRKSRC}/lopan.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lopan ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
