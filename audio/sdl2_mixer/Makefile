# $FreeBSD$

PORTNAME=	sdl2_mixer
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL2_mixer-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Sample multi-channel audio mixer library

LICENSE=	ZLIB
LICENSE_FILE_ZLIB=${WRKSRC}/COPYING.txt

USES=		gmake libtool localbase pathfix pkgconfig sdl
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# disabled dynamic loading of shared libraries, not shared linking
CONFIGURE_ARGS=	--disable-music-mod-modplug-shared \
		--disable-music-mod-mikmod-shared \
		--disable-music-midi-fluidsynth-shared \
		--disable-music-ogg-shared \
		--disable-music-flac-shared \
		--disable-music-mp3-mpg123-shared \
		--disable-music-opus-shared

OPTIONS_DEFINE=		FLAC OPUS
OPTIONS_RADIO=		MOD MIDI OGG MP3
OPTIONS_RADIO_MOD=	MIKMOD MODPLUG
OPTIONS_RADIO_MIDI=	FLUIDSYNTH
OPTIONS_RADIO_OGG=	VORBIS TREMOR
OPTIONS_RADIO_MP3=	MAD MPG123
OPTIONS_DEFAULT=	FLUIDSYNTH MODPLUG FLAC OPUS MPG123

.if defined(MACHINE_CPU) && ${MACHINE_CPU:Msoftfp}
OPTIONS_DEFAULT+=	TREMOR
.else
OPTIONS_DEFAULT+=	VORBIS
.endif

# MOD
MOD_DESC=			Tracker music support

MIKMOD_LIB_DEPENDS=		libmikmod.so:audio/libmikmod
MIKMOD_CONFIGURE_ENABLE=	music-mod-mikmod

MODPLUG_LIB_DEPENDS=		libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	music-mod-modplug

# MIDI
MIDI_DESC=			MIDI music support

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ENABLE=	music-midi-fluidsynth

# TODO: add timidity?

# OGG
VORBIS_LIB_DEPENDS=		libvorbis.so:audio/libvorbis

TREMOR_LIB_DEPENDS=		libvorbisidec.so:audio/libtremor
TREMOR_CONFIGURE_ENABLE=	music-ogg-tremor

# MP3
MAD_LIB_DEPENDS=		libmad.so:audio/libmad
MAD_CONFIGURE_ENABLE=		music-mp3-mad-gpl
MAD_VARS=			LICENSE+=GPLv2+ LICENSE_COMB=multi

MPG123_LIB_DEPENDS=		libmpg123.so:audio/mpg123
MPG123_CONFIGURE_ENABLE=	music-mp3-mpg123

# Others
FLAC_LIB_DEPENDS=		libFLAC.so:audio/flac
FLAC_CONFIGURE_ENABLE=		music-flac

OPUS_LIB_DEPENDS=		libopusfile.so:audio/opusfile
OPUS_CONFIGURE_ENABLE=		music-opus

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MVORBIS} && !${PORT_OPTIONS:MTREMOR}
CONFIGURE_ARGS+=		--disable-music-ogg
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\($$(prefix)/libdata/pkgconfig\)|$$(DESTDIR)\1|' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libSDL2_mixer.so

.include <bsd.port.mk>
