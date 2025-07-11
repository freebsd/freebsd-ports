PORTNAME=	sdl_jewels
DISTVERSION=	1.1.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	https://www.linuxmotors.com/linux/gljewel/downloads/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME:S/sdl/SDL/}-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME:S/sdl/SDL/}-${DISTVERSION}.tgz

MAINTAINER=	seafork@disroot.org
COMMENT=	Tile-matching 8x8 puzzle game
WWW=		https://www.linuxmotors.com/linux/gljewel/

LICENSE=	UNKNOWN
LICENSE_NAME=	Unknown
LICENSE_TEXT=	The license is unknown.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gl gmake sdl
USE_GL=		gl
USE_SDL=	image mixer sdl
ALL_TARGET=	# empty

DESKTOP_ENTRIES=	"SDL Jewels" \
			"" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Game;BoardGame;" \
			""

WRKSRC=		${WRKDIR}/${PORTNAME:S/sdl/SDL/}-${DISTVERSION}

PORTDOCS=	ChangeLog README
OPTIONS_DEFINE=	DOCS

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
