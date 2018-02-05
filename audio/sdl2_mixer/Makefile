# $FreeBSD$

PORTNAME=	sdl2_mixer
PORTVERSION=	2.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL2_mixer-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Sample multi-channel audio mixer library

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gmake pathfix pkgconfig libtool localbase
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		FLUIDSYNTH FLAC SMPEG
OPTIONS_DEFAULT=	FLUIDSYNTH MODPLUG FLAC SMPEG
OPTIONS_RADIO=		MOD OGG
OPTIONS_RADIO_MOD=	MIKMOD MODPLUG
OPTIONS_RADIO_OGG=	VORBIS TREMOR

.if defined(MACHINE_CPU) && ${MACHINE_CPU:Msoftfp}
OPTIONS_DEFAULT+=	TREMOR
.else
OPTIONS_DEFAULT+=	VORBIS
.endif

MOD_DESC=	Tracker music support
SMPEG_DESC=	MP3 audio support via SMPEG2

MIKMOD_LIB_DEPENDS=		libmikmod.so:audio/libmikmod
MIKMOD_CONFIGURE_ENABLE=	music-mod-mikmod

MODPLUG_LIB_DEPENDS=		libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	music-mod-modplug

FLAC_LIB_DEPENDS=		libFLAC.so:audio/flac
FLAC_CONFIGURE_ENABLE=		music-flac

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ON=	--enable-music-midi --enable-music-midi-fluidsynth
FLUIDSYNTH_CONFIGURE_OFF=	--disable-music-midi --disable-music-midi-fluidsynth

SMPEG_LIB_DEPENDS=		libsmpeg2.so:multimedia/smpeg2
SMPEG_CONFIGURE_ON=		--enable-music-mp3 --enable-music-mp3-smpeg
SMPEG_CONFIGURE_OFF=		--disable-music-mp3 --disable-music-mp3-smpeg

VORBIS_LIB_DEPENDS=		libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	music-ogg

TREMOR_LIB_DEPENDS=		libvorbisidec.so:audio/libtremor
TREMOR_CONFIGURE_ON=		--enable-music-ogg
# TREMOR_CONFIGURE_OFF is handled by VORBIS=off
TREMOR_CONFIGURE_ENABLE=	music-ogg-tremor

post-patch:
	@${REINPLACE_CMD} -e 's|\($$(prefix)/libdata/pkgconfig\)|$$(DESTDIR)\1|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|"modplug.h"|"libmodplug/modplug.h"|' \
		${WRKSRC}/dynamic_modplug.h ${WRKSRC}/music_modplug.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libSDL2_mixer.so

.include <bsd.port.mk>
