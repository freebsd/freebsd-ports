# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	sdl_sound
PORTVERSION=	1.0.3
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://offload1.icculus.org:9090/SDL_sound/downloads/ \
		http://offload2.icculus.org:9090/SDL_sound/downloads/
DISTNAME=	SDL_sound-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A SDL audio library and player for some popular sound file formats

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_SDL=	sdl
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		FLAC MIKMOD MIDI MODPLUG PHYSFS SMPEG SPEEX VORBIS
OPTIONS_DEFAULT=	FLAC MIKMOD MIDI MODPLUG PHYSFS SMPEG SPEEX VORBIS

MIDI_DESC=	Software MIDI music
PHYSFS_DESC=	PhysicsFS support
SMPEG_DESC=	MP3 audio format

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if ${PORT_OPTIONS:MMIKMOD}
LIB_DEPENDS+=	mikmod:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=--disable-mikmod
.endif

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug
.else
CONFIGURE_ARGS+=--disable-modplug
.endif

.if ${PORT_OPTIONS:MPHYSFS}
LIB_DEPENDS+=	physfs:${PORTSDIR}/devel/physfs
.else
CONFIGURE_ARGS+=--disable-physfs
.endif

.if ${PORT_OPTIONS:MSMPEG}
LIB_DEPENDS+=	smpeg:${PORTSDIR}/multimedia/smpeg
CONFIGURE_ARGS+=--disable-mpglib
.else
CONFIGURE_ARGS+=--disable-smpeg
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex
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
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
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
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/decoders/timidity/options.h

.include <bsd.port.post.mk>
