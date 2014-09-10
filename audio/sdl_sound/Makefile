# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	sdl_sound
PORTVERSION=	1.0.3
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://offload1.icculus.org:9090/SDL_sound/downloads/ \
		http://offload2.icculus.org:9090/SDL_sound/downloads/
DISTNAME=	SDL_sound-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	SDL audio library and player for some popular sound file formats

USES=		libtool
USE_LDCONFIG=	yes
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		FLAC MIKMOD MIDI MODPLUG PHYSFS SMPEG SPEEX VORBIS
OPTIONS_DEFAULT=	FLAC MIKMOD MIDI MODPLUG PHYSFS SMPEG SPEEX VORBIS

MIDI_DESC=	Software MIDI music
PHYSFS_DESC=	PhysicsFS support
SMPEG_DESC=	MP3 audio format

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if ${PORT_OPTIONS:MMIKMOD}
LIB_DEPENDS+=	libmikmod.so:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=--disable-mikmod
.endif

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	libmodplug.so:${PORTSDIR}/audio/libmodplug
.else
CONFIGURE_ARGS+=--disable-modplug
.endif

.if ${PORT_OPTIONS:MPHYSFS}
LIB_DEPENDS+=	libphysfs.so:${PORTSDIR}/devel/physfs
.else
CONFIGURE_ARGS+=--disable-physfs
.endif

.if ${PORT_OPTIONS:MSMPEG}
LIB_DEPENDS+=	libsmpeg.so:${PORTSDIR}/multimedia/smpeg
CONFIGURE_ARGS+=--disable-mpglib
.else
CONFIGURE_ARGS+=--disable-smpeg
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	libspeex.so:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if ${PORT_OPTIONS:MMIDI}
RUN_DEPENDS+=	${LOCALBASE}/lib/timidity/goemon.cfg:${PORTSDIR}/audio/timidity
BUILD_DEPENDS+=	${LOCALBASE}/lib/timidity/goemon.cfg:${PORTSDIR}/audio/timidity
.else
CONFIGURE_ARGS+=--disable-midi
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-ogg
.endif

pre-everything::
.if !${PORT_OPTIONS:MSMPEG}
	@${ECHO_CMD}
	@${ECHO_CMD} "WARNING: the built-in MP3 support is currently broken, consider enabling the SMPEG option to use that library instead." | ${FMT}
	@${ECHO_CMD}
.endif

post-patch:
	@${REINPLACE_CMD} 's|timidity.cfg|${PREFIX}/share/timidity/&|' \
		${WRKSRC}/decoders/timidity/options.h

.include <bsd.port.mk>
