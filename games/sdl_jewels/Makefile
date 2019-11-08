# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_jewels
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/gljewel/downloads/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME:S/sdl/SDL/}-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME:S/sdl/SDL/}-${DISTVERSION}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tile-matching 8x8 puzzle game

WRKSRC=		${WRKDIR}/${PORTNAME:S/sdl/SDL/}-${PORTVERSION}

USES=		gmake sdl
USE_SDL=	sdl image mixer
ALL_TARGET=	# empty

PORTDOCS=	ChangeLog README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="SDL Jewels" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;BoardGame;" ""

post-patch:
	@${RM} -r ${WRKSRC}/data/CVS
	@${REINPLACE_CMD} -e 's|data/bigfont.ppm|${DATADIR}/data/bigfont.ppm| ; \
	s|dirlist\[\]="data";|dirlist[]="${DATADIR}/data";| ; \
	s|char name[256],|char name[512],|' \
		${WRKSRC}/gljewel.c ${WRKSRC}/sound.c
	@${REINPLACE_CMD} -e 's|CFLAGS = -O2 -Wall|CFLAGS+=| ; \
	s|LDFLAGS =|LDFLAGS+=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gljewel ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
