# New ports collection makefile for:	OpenTTD
# Date created:				16 Dec 2004
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openttd
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://gb.binaries.openttd.org/binaries/releases/${PORTVERSION}/ \
		#SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An open source clone of Microprose Transport Tycoon Deluxe

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		lzo2.2:${PORTSDIR}/archivers/lzo2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix-dir="${PREFIX}" --data-dir="${DATADIR_REL}"
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

DISTVERSIONSUFFIX=	-source
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if defined(WITH_MIDI_PLAYER)
CONFIGURE_ARGS+=	--with-midi=${WITH_MIDI_PLAYER}
.endif
.if defined(WITH_MIDI_PLAYER_ARGS)
CONFIGURE_ARGS+=	--with-midi-arg=${WITH_MIDI_PLAYER_ARGS}
.endif
.if defined(WITH_DEDICATED_SERVER_ONLY)
CONFIGURE_ARGS+=	--enable-dedicated
# Aid it to find lzo2 headers; client build gets it via sdl-config
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include"
.else
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
USE_SDL=	sdl
.endif

SUB_FILES=	pkg-message
MAN6=		openttd.6

DESKTOP_ENTRIES="OpenTTD" "${COMMENT}" "openttd" "openttd" \
		"Game;Simulation;StrategyGame;" false

PORTDOCS=	32bpp.txt HOWTO_compile_lang_files.txt elrail.svg \
		elrail_tile.png elrail_track.png landscape.html \
		landscape_externals.html landscape_grid.html multiplayer.txt \
		obg_format.txt obm_format.txt obs_format.txt \
		ottd-colour-palette.gif ottd-colourtext-palette.png tileh.png

pre-everything::
.if !defined(WITH_MIDI_PLAYER)
	@${ECHO_MSG} "Define WITH_MIDI_PLAYER=/path/to/player to build with external MIDI player"
.endif
.if !defined(WITH_MIDI_PLAYER_ARGS)
	@${ECHO_MSG} "Define WITH_MIDI_PLAYER_ARGS=arguments for external MIDI player"
.endif
.if !defined(WITH_DEDICATED_SERVER_ONLY)
	@${ECHO_MSG} "Define WITH_DEDICATED_SERVER_ONLY to build CLI-based dedicated server"
.endif

post-patch:
# Remove extra (vendor-provided) CFLAGS and LDFLAGS
	@${REINPLACE_CMD} -e '1250,1252d' ${WRKSRC}/config.lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/ai ${DATADIR}/data ${DATADIR}/gm \
		${DATADIR}/lang ${DATADIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/bin/ai/*.nut ${DATADIR}/ai
	${INSTALL_DATA} ${WRKSRC}/bin/data/* ${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/bin/gm/* ${DATADIR}/gm
	${INSTALL_DATA} ${WRKSRC}/bin/lang/* ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/bin/scripts/* ${DATADIR}/scripts
	${INSTALL_MAN} ${WRKSRC}/docs/${MAN6} ${MANPREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/media/openttd.32.xpm ${PREFIX}/share/pixmaps
.for n in 16 32 48 64 128 256
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} ${WRKSRC}/media/openttd.${n}.png \
		${PREFIX}/share/icons/hicolor/${n}x${n}/apps/openttd.png
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
