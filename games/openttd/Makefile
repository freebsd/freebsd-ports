# New ports collection makefile for:	OpenTTD
# Date created:				16 Dec 2004
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openttd
PORTVERSION=	0.7.2
CATEGORIES=	games
MASTER_SITES=	SF http://binaries.openttd.org/releases/${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An open source clone of Microprose Transport Tycoon Deluxe

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--prefix-dir="${PREFIX}" --data-dir="${DATADIR_REL}"

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
.else
USE_SDL=	sdl
.endif

SUB_FILES=	pkg-message
MAN6=		openttd.6

DESKTOP_ENTRIES="OpenTTD" "${COMMENT}" "openttd" "openttd" \
		"Game;Simulation;StrategyGame;" false

DOCS=		32bpp.txt HOWTO_compile_lang_files.txt Manual.txt elrail.svg \
		elrail_tile.png elrail_track.png landscape.html \
		landscape_externals.html landscape_grid.html multiplayer.txt \
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
# Remove extra (vendor) CFLAGS, we set our own
	@${REINPLACE_CMD} '1096,1097d' ${WRKSRC}/config.lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/data ${DATADIR}/lang ${DATADIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/bin/data/* ${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/bin/lang/* ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/bin/scripts/* ${DATADIR}/scripts
	${INSTALL_MAN} ${WRKSRC}/docs/${MAN6} ${MANPREFIX}/man/man6
.for n in 16 32 48 64 128 256
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} ${WRKSRC}/media/openttd.${n}.png \
		${PREFIX}/share/icons/hicolor/${n}x${n}/apps/openttd.png
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
. endfor
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
