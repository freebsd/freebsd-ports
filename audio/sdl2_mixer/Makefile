# $FreeBSD$

PORTNAME=	sdl2_mixer
PORTVERSION=	2.0.0
PORTREVISION=	3
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

OPTIONS_DEFINE=		FLUIDSYNTH FLAC VORBIS
OPTIONS_DEFAULT=	FLUIDSYNTH MODPLUG FLAC VORBIS
OPTIONS_RADIO=		MOD
OPTIONS_RADIO_MOD=	MIKMOD MODPLUG

FLUIDSYNTH_DESC=	Enable SoundFont2 Midi support via fluidsynth
MIKMOD_DESC=	Enable MOD music via libMikMod
MODPLUG_DESC=	Enable MOD music via libModPlug
FLAC_DESC=	Enable FLAC encoding support via flac
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

VORBIS_LIB_DEPENDS=		libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	music-ogg

post-patch:
	@${REINPLACE_CMD} -e 's|\($$(prefix)/libdata/pkgconfig\)|$$(DESTDIR)\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
