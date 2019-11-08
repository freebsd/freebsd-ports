# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_scavenger
PORTVERSION=	145.2015.01.05
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/sdlscavenger/
DISTNAME=	sdlscav-145.4_2015_01_05

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lode Runner like game

LICENSE=	GPLv1

WRKSRC=		${WRKDIR}/sdlscav-145

USES=		gmake sdl shebangfix tar:tgz
SHEBANG_FILES=	scavsaver
bash_CMD=	/bin/sh
USE_SDL=	sdl image mixer
ALL_TARGET=

PORTDOCS=	CREDITS DOC NEW_FEATURES README STRATEGY

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="SDL Scavenger" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|; \
		s|-O2 ||; \
		s|$$HOME/.scavenger|$$HOME/.sdlscavenger|; \
		s||$$(DESTDIR)/usr/local/bin|; \
		s|/usr/local/bin|$$(DESTDIR)/usr/local/bin|; \
		s|/usr/local/games/scavenger|$$(DESTDIR)/usr/local/share/${PORTNAME}|; \
		s|sdlscav $$(DESTDIR)/usr/local/bin/|sdlscav $$(DESTDIR)/usr/local/bin/${PORTNAME}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local/games/scavenger|${DATADIR}|; \
		s|".scavenger"|".sdlscavenger"|' \
		${WRKSRC}/names.h
	@${REINPLACE_CMD} -e 's|sdlscav|sdl_scavenger|' ${WRKSRC}/scavsaver

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/data/scav.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
