# New ports collection makefile for:	sdl_sound
# Date created:				6 Feb 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	sdl_sound
PORTVERSION=	1.0.3
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://offload1.icculus.org:9090/SDL_sound/downloads/ \
		http://offload2.icculus.org:9090/SDL_sound/downloads/
DISTNAME=	SDL_sound-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A SDL audio library and player for some popular sound file formats

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_SDL=	sdl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	FLAC "Enable FLAC decoding support" on \
		MIKMOD "Enable MOD decoding support using mikmod" on \
		MIDI "Enable software MIDI music" on \
		MODPLUG "Enable MOD decoding support using modplug" on \
		PHYSFS "Enable PhysicsFS support" on \
		SMPEG "Enable MP3 decoding support" on \
		SPEEX "Enable SPX decoding support" on \
		VORBIS "Enable Ogg Vorbis decoding support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if !defined(WITHOUT_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=--disable-mikmod
.endif

.if !defined(WITHOUT_MODPLUG)
LIB_DEPENDS+=	modplug.1:${PORTSDIR}/audio/libmodplug
.else
CONFIGURE_ARGS+=--disable-modplug
.endif

.if !defined(WITHOUT_PHYSFS)
LIB_DEPENDS+=	physfs.1:${PORTSDIR}/devel/physfs
.else
CONFIGURE_ARGS+=--disable-physfs
.endif

.if !defined(WITHOUT_SMPEG)
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
CONFIGURE_ARGS+=--disable-mpglib
.else
CONFIGURE_ARGS+=--disable-smpeg
.endif

.if !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if !defined(WITHOUT_MIDI)
RUN_DEPENDS+=	${LOCALBASE}/lib/timidity/goemon.cfg:${PORTSDIR}/audio/timidity
BUILD_DEPENDS+=	${LOCALBASE}/lib/timidity/goemon.cfg:${PORTSDIR}/audio/timidity
.else
CONFIGURE_ARGS+=--disable-midi
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-ogg
.endif

.if defined(WITHOUT_SMPEG)
pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "WARNING: the built-in MP3 support is currently broken, consider enabling the SMPEG option to use that library instead." | ${FMT}
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
