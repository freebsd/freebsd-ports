# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openttd
PORTVERSION=	1.3.2
CATEGORIES=	games
MASTER_SITES=	http://ftp.snt.utwente.nl/pub/games/openttd/binaries/releases/${PORTVERSION}/ \
		http://us.binaries.openttd.org/binaries/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open source clone of Microprose Transport Tycoon Deluxe

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		lzo2:${PORTSDIR}/archivers/lzo2

USES=		gmake
USE_XZ=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	STRIP="${STRIP_CMD} ${STRIP}"
CONFIGURE_ARGS=	--prefix-dir="${PREFIX}" --data-dir="${DATADIR_REL}"
MAKE_ARGS=	VERBOSE=1		# We want to see what's going on

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CXXFLAGS=	# Set to empty as OpenTTD treats it as an addition to CFLAGS

SUB_FILES=	pkg-message
MAN6=		${PORTNAME}.6

PORTDOCS=	HOWTO_compile_lang_files.txt admin_network.txt \
		elrail.svg elrail_tile.png elrail_track.png landscape.html \
		landscape_externals.html landscape_grid.html multiplayer.txt \
		obg_format.txt obm_format.txt obs_format.txt \
		ottd-colourtext-palette.png tileh.png

DESKTOP_ENTRIES="OpenTTD" "${COMMENT}" "${PORTNAME}" "${PORTNAME}" \
		"Game;Simulation;StrategyGame;" false

.if defined(WITH_MIDI_PLAYER)
CONFIGURE_ARGS+=	--with-midi="${WITH_MIDI_PLAYER}"
.endif

.if defined(WITH_MIDI_PLAYER_ARGS)
CONFIGURE_ARGS+=	--with-midi-arg="${WITH_MIDI_PLAYER_ARGS}"
.endif

.if defined(WITH_DEDICATED_SERVER_ONLY)
USE_GNOME=	pkgconfig			# Needed for liblzma support
CONFIGURE_ARGS+=	--enable-dedicated
# Aid it to find lzo2 headers; client build gets it via sdl-config
CFLAGS+=	-I${LOCALBASE}/include
USE_RC_SUBR=	${PORTNAME}
.else
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
USE_SDL=	sdl
INSTALLS_ICONS=	yes
.endif

.if defined(WITH_OPEN_GAME_FILES)
RUN_DEPENDS+=	${LOCALBASE}/share/${PORTNAME}/baseset/opengfx/opengfx.obg:${PORTSDIR}/games/opengfx \
		${LOCALBASE}/share/${PORTNAME}/baseset/openmsx/openmsx.obm:${PORTSDIR}/games/openmsx \
		${LOCALBASE}/share/${PORTNAME}/baseset/opensfx/opensfx.obs:${PORTSDIR}/games/opensfx
.endif

.include <bsd.port.pre.mk>

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
.if !defined(WITH_OPEN_GAME_FILES)
	@${ECHO_MSG} "Define WITH_OPEN_GAME_FILES to install with libre graphics, music, and sounds"
.endif

post-patch:
# Remove extra (vendor-provided) CFLAGS and LDFLAGS and make the port more
# LOCALBASE safe
	@${REINPLACE_CMD} -e '/-O2 -fomit-frame-pointer/d ; \
		s,/usr/local,${LOCALBASE},' ${WRKSRC}/config.lib
# Use custom liblzma.pc for when we use liblzma from base
.if ${OSVERSION} >= 900012 || (${OSVERSION} >= 800505 && ${OSVERSION} < 900000)
	@${REINPLACE_CMD} -e \
		's,pkg-config liblzma,pkg-config ${FILESDIR}/liblzma.pc,' \
			${WRKSRC}/config.lib
.else
LIB_DEPENDS+=	lzma:${PORTSDIR}/archivers/xz
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/ai ${DATADIR}/baseset ${DATADIR}/lang \
		${DATADIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/bin/ai/*.nut ${DATADIR}/ai
	${INSTALL_DATA} ${WRKSRC}/bin/baseset/* ${DATADIR}/baseset
	${INSTALL_DATA} ${WRKSRC}/bin/lang/* ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/bin/scripts/* ${DATADIR}/scripts
	${INSTALL_MAN} ${WRKSRC}/docs/${MAN6} ${MANPREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/media/openttd.32.xpm ${PREFIX}/share/pixmaps
.if !defined(WITH_DEDICATED_SERVER_ONLY)
.  for n in 16 32 48 64 128 256
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} ${WRKSRC}/media/openttd.${n}.png \
		${PREFIX}/share/icons/hicolor/${n}x${n}/apps/openttd.png
.  endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${DOCSDIR}
.endif

post-install:
.if defined(WITH_DEDICATED_SERVER_ONLY)
	@${REINPLACE_CMD} -e '/icons/d' ${TMPPLIST}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
