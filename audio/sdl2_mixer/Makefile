# $FreeBSD$

PORTNAME=	sdl2_mixer
PORTVERSION=	2.0.p2
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/tmp/SDL_mixer/release/
DISTNAME=	SDL2_mixer-2.0.0

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A sample multi-channel audio mixer library

LICENSE=	ZLIB

USES=		pathfix pkgconfig:build
USE_GMAKE=	yes
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		FLUIDSYNTH MODPLUG FLAC VORBIS
OPTIONS_DEFAULT=	FLUIDSYNTH MODPLUG FLAC VORBIS

FLUIDSYNTH_DESC=	Enable SoundFont2 Midi support via fluidsynth
MODPLUG_DESC=	Enable MOD music via libModPlug
FLAC_DESC=	Enable FLAC encoding support via flac
VORBIS_DESC=	Enable Ogg Vorbis music

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=		modplug:${PORTSDIR}/audio/libmodplug
CONFIGURE_ARGS+=	--enable-music-mod --enable-music-mod-modplug
.else
CONFIGURE_ARGS+=	--disable-music-mod --disable-music-mod-modplug
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=		FLAC:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=	--enable-music-flac
.else
CONFIGURE_ARGS+=	--disable-music-flac
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
LIB_DEPENDS+=		fluidsynth:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=	--enable-music-midi --enable-music-midi-fluidsynth
.else
CONFIGURE_ARGS+=	--disable-music-midi --disable-music-midi-fluidsynth
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=		vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-music-ogg
.else
CONFIGURE_ARGS+=	--disable-music-ogg
.endif

.include <bsd.port.mk>
