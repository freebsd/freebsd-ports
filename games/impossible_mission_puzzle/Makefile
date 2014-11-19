# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	impossible_mission_puzzle
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/puzzle/downloads/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	puzzle-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	puzzle-${DISTVERSION}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This is a puzzle from the old C64 Impossible Mission game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/puzzle-${PORTVERSION}

USE_SDL=	sdl

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	README

DESKTOP_ENTRIES="Impossible Mission puzzle" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-build:
	@cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
	`${SDL_CONFIG} --cflags --libs` puzzle.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
