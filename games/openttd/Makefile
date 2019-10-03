# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openttd
DISTVERSION=	1.9.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	https://proxy.binaries.openttd.org/openttd-releases/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open source clone of Microprose Transport Tycoon Deluxe

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		liblzo2.so:archivers/lzo2

USES=		cpe gmake pkgconfig tar:xz
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	STRIP="${STRIP_CMD} ${STRIP}"
CONFIGURE_ARGS=	--prefix-dir="${PREFIX}" --data-dir="${DATADIR_REL}" \
		--without-libtimidity
MAKE_ARGS=	VERBOSE=1

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
CXXFLAGS=	# Set to empty as OpenTTD treats it as an addition to CFLAGS

SUB_FILES=	pkg-message

PORTDOCS=	HOWTO_compile_lang_files.txt README.md admin_network.txt \
		changelog.txt elrail.svg elrail_tile.png elrail_track.png \
		known-bugs.txt landscape.html landscape_externals.html \
		landscape_grid.html multiplayer.txt obg_format.txt \
		obm_format.txt obs_format.txt ottd-colourtext-palette.png \
		tileh.png

DESKTOP_ENTRIES="OpenTTD" "${COMMENT}" "${PORTNAME}" "${PORTNAME}" \
		"Game;Simulation;StrategyGame;" false

OPTIONS_DEFINE=	DOCS

.if defined(WITH_MIDI_PLAYER)
CONFIGURE_ARGS+=	--with-midi="${WITH_MIDI_PLAYER}"
.endif

.if defined(WITH_MIDI_PLAYER_ARGS)
CONFIGURE_ARGS+=	--with-midi-arg="${WITH_MIDI_PLAYER_ARGS}"
.endif

.if defined(WITH_FLUIDSYNTH)
LIB_DEPENDS+=	libfluidsynth.so:audio/fluidsynth
.else
CONFIGURE_ARGS+=	--without-fluidsynth
.endif

.if defined(WITH_DEDICATED_SERVER_ONLY)
CONFIGURE_ARGS+=	--enable-dedicated
# Aid it to find lzo2 headers; client build gets it via sdl-config
CFLAGS+=	-I${LOCALBASE}/include
USE_RC_SUBR=	${PORTNAME}
.else
USES+=		compiler:c++11-lib sdl
USE_CXXSTD=	gnu++11
CXXFLAGS+=	-DU_USING_ICU_NAMESPACE=1
LIB_DEPENDS+=	libfreetype.so:print/freetype2 \
		libicui18n.so:devel/icu \
		libicu-le-hb.so:devel/icu-le-hb \
		libiculx.so:devel/icu-lx \
		libfontconfig.so:x11-fonts/fontconfig
USE_SDL=	sdl
INSTALLS_ICONS=	yes
.endif

.if defined(WITH_OPEN_GAME_FILES)
RUN_DEPENDS+=	${LOCALBASE}/share/${PORTNAME}/baseset/opengfx/opengfx.obg:games/opengfx \
		${LOCALBASE}/share/${PORTNAME}/baseset/openmsx/openmsx.obm:games/openmsx \
		${LOCALBASE}/share/${PORTNAME}/baseset/opensfx/opensfx.obs:games/opensfx
.endif

.if defined(WITH_SAVE_PASSWORDS)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-save-passwords
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_MIDI_PLAYER)
	@${ECHO_MSG} "Define WITH_MIDI_PLAYER=/path/to/player to build with external MIDI player"
.endif
.if !defined(WITH_MIDI_PLAYER_ARGS)
	@${ECHO_MSG} "Define WITH_MIDI_PLAYER_ARGS=arguments for external MIDI player"
.endif
.if !defined(WITH_FLUIDSYNTH)
	@${ECHO_MSG} "Define WITH_FLUIDSYNTH to enable new Fluidsynth music driver"
.endif
.if !defined(WITH_DEDICATED_SERVER_ONLY)
	@${ECHO_MSG} "Define WITH_DEDICATED_SERVER_ONLY to build CLI-based dedicated server"
.endif
.if !defined(WITH_OPEN_GAME_FILES)
	@${ECHO_MSG} "Define WITH_OPEN_GAME_FILES to install with libre graphics, music, and sounds"
.endif
.if !defined(WITH_SAVE_PASSWORDS)
	@${ECHO_MSG} "Define WITH_SAVE_PASSWORDS to save passwords between server restarts"
.endif

post-extract:
	@${MV} ${WRKSRC}/README.md ${WRKSRC}/changelog.txt \
		${WRKSRC}/known-bugs.txt ${WRKSRC}/docs

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' ${WRKSRC}/config.lib
	@${REINPLACE_CMD} -e 's,OSX,${OPSYS:tu},' ${WRKSRC}/Makefile.grf.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/ai ${STAGEDIR}${DATADIR}/baseset \
		${STAGEDIR}${DATADIR}/game ${STAGEDIR}${DATADIR}/lang \
		${STAGEDIR}${DATADIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/bin/ai/*.nut ${STAGEDIR}${DATADIR}/ai
	${INSTALL_DATA} ${WRKSRC}/bin/baseset/* ${STAGEDIR}${DATADIR}/baseset
	${INSTALL_DATA} ${WRKSRC}/bin/game/* ${STAGEDIR}${DATADIR}/game
	${INSTALL_DATA} ${WRKSRC}/bin/lang/* ${STAGEDIR}${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/bin/scripts/* ${STAGEDIR}${DATADIR}/scripts
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.6 \
		${STAGEDIR}${MANPREFIX}/man/man6
.if !defined(WITH_DEDICATED_SERVER_ONLY)
	${INSTALL_DATA} ${WRKSRC}/media/openttd.32.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps
.  for n in 16 32 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} ${WRKSRC}/media/openttd.${n}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps/openttd.png
.  endfor
.else
	@${REINPLACE_CMD} -E '/icons|pixmaps/d' ${TMPPLIST}
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
