# $FreeBSD$

PORTNAME=	sdl_jewels
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/gljewel/downloads/ \
		http://www.linuxmotors.com/gljewel/:icons
DISTFILES=	${PORTNAME:S/sdl/SDL/}-${DISTVERSION}.tgz \
		gljewel.gif:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME:S/sdl/SDL/}-${DISTVERSION}.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Tile-matching 8x8 puzzle game

LICENSE=	GPLv2

BUILD_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm

WRKSRC=		${WRKDIR}/${PORTNAME:S/sdl/SDL/}-${PORTVERSION}

USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
ALL_TARGET=

PLIST_FILES=	bin/sdljewels \
		share/pixmaps/sdljewels.png

PORTDATA=	*
PORTDOCS=	ChangeLog README

DESKTOP_ENTRIES="SDL Jewels" "${COMMENT}" "sdljewels" \
		"sdljewels" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

post-patch:
	@${RM} -rf ${WRKSRC}/data/CVS
	@${REINPLACE_CMD} -e 's|data/bigfont.ppm|${DATADIR}/data/bigfont.ppm|' \
	-e 's|dirlist\[\]="data";|dirlist[]="${DATADIR}/data";|' \
	-e 's|char name[256],|char name[512],|' \
		${WRKSRC}/gljewel.c ${WRKSRC}/sound.c
	@${REINPLACE_CMD} -e 's|CFLAGS = -O2 -Wall|CFLAGS+=|' \
	-e 's|LDFLAGS =|LDFLAGS+=|' ${WRKSRC}/Makefile

post-build:
	@(cd ${WRKSRC} && \
		${LOCALBASE}/bin/giftopnm ${DISTDIR}/${DIST_SUBDIR}/gljewel.gif | \
		${LOCALBASE}/bin/pamscale .1 | ${LOCALBASE}/bin/pnmtopng > sdljewels.png)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gljewel ${PREFIX}/bin/sdljewels
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/sdljewels.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
