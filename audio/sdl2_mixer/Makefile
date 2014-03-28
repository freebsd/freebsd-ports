# $FreeBSD$

PORTNAME=	sdl2_mixer
PORTVERSION=	2.0.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL2_mixer-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A sample multi-channel audio mixer library

LICENSE=	ZLIB

USES=		gmake pathfix pkgconfig
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		FLUIDSYNTH FLAC SMPEG VORBIS
OPTIONS_DEFAULT=	FLUIDSYNTH MODPLUG FLAC SMPEG VORBIS
OPTIONS_RADIO=		MOD
OPTIONS_RADIO_MOD=	MIKMOD MODPLUG

FLUIDSYNTH_DESC=	Enable SoundFont2 Midi support via fluidsynth
MIKMOD_DESC=	Enable MOD music via libMikMod
MODPLUG_DESC=	Enable MOD music via libModPlug
FLAC_DESC=	Enable FLAC encoding support via flac
SMPEG_DESC=	Enable MP3 music via SMPEG2
VORBIS_DESC=	Enable Ogg Vorbis music

MIKMOD_LIB_DEPENDS=		libmikmod.so:${PORTSDIR}/audio/libmikmod
MIKMOD_CONFIGURE_ENABLE=	music-mod-mikmod

MODPLUG_LIB_DEPENDS=		libmodplug.so:${PORTSDIR}/audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	music-mod-modplug

FLAC_LIB_DEPENDS=		libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CONFIGURE_ENABLE=		music-flac

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:${PORTSDIR}/audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ON=	--enable-music-midi --enable-music-midi-fluidsynth
FLUIDSYNTH_CONFIGURE_OFF=	--disable-music-midi --disable-music-midi-fluidsynth

SMPEG_LIB_DEPENDS=		libsmpeg2.so:${PORTSDIR}/multimedia/smpeg2
SMPEG_CONFIGURE_ON=		--enable-music-mp3 --enable-music-mp3-smpeg
SMPEG_CONFIGURE_OFF=		--disable-music-mp3 --disable-music-mp3-smpeg

VORBIS_LIB_DEPENDS=		libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	music-ogg

post-patch:
	@${REINPLACE_CMD} -e 's|\($$(prefix)/libdata/pkgconfig\)|$$(DESTDIR)\1|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|"modplug.h"|"libmodplug/modplug.h"|' \
		${WRKSRC}/dynamic_modplug.h ${WRKSRC}/music_modplug.h

.include <bsd.port.mk>
