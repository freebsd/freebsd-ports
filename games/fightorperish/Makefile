# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fightorperish
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/fop/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	fop-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	fop-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dungeon-crawling game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

WRKSRC=		${WRKDIR}/fop-${DISTVERSION}

USES=		gmake
USE_SDL=	image mixer sdl

PORTDOCS=	CHANGES.txt README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Fight or Perish" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/data/| ; \
		s|char [256],|char [512],|' ${WRKSRC}/src/fop.c
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}| ; \
		s|CFLAGS=-Wall -O2|CFLAGS+=| ; \
		s|SDL_CFLAGS=|SDL_CFLAGS+=| ; \
		s|SDL_LIBS=|SDL_LIBS+=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fop ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "images maps sounds" \
		${STAGEDIR}${DATADIR}/data)

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
