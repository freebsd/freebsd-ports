# New ports collection makefile for:	sdl_sound
# Date created:				6 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	sdl_sound
PORTVERSION=	1.0.1
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.icculus.org/SDL_sound/downloads/
DISTNAME=	SDL_sound-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A SDL audio library and player for some popular sound file formats

USE_SDL=	sdl
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !defined(WITHOUT_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=	--disable-mikmod
.endif

.if !defined(WITHOUT_PHYSFS)
LIB_DEPENDS+=	physfs-1.0.1:${PORTSDIR}/devel/physfs
.else
CONFIGURE_ARGS+=	--disable-physfs
.endif

.if !defined(WITHOUT_SMPEG)
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
.else
CONFIGURE_ARGS+=	--disable-smpeg
.endif

.if !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.3:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=	--disable-speex
.endif

.if !defined(WITHOUT_MIDI)
RUN_DEPENDS+=	${LOCALBASE}/lib/timidity/goemon.cfg:${PORTSDIR}/audio/timidity
BUILD_DEPENDS+=	${LOCALBASE}/lib/timidity/goemon.cfg:${PORTSDIR}/audio/timidity
.else
CONFIGURE_ARGS+=	--disable-midi
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif

pre-extract:
.if !defined(WITHOUT_FLAC)
	@${ECHO_MSG} "You can disable support for flac by defining WITHOUT_FLAC."
.endif
.if !defined(WITHOUT_MIKMOD)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_MIKMOD."
.endif
.if !defined(WITHOUT_PHYSFS)
	@${ECHO_MSG} "You can disable support for physfs by defining WITHOUT_PHYSFS."
.endif
.if !defined(WITHOUT_SMPEG)
	@${ECHO_MSG} "You can disable support for smpeg by defining WITHOUT_SMPEG."
.endif
.if !defined(WITHOUT_SPEEX)
	@${ECHO_MSG} "You can disable support for speex by defining WITHOUT_SPEEX."
.endif
.if !defined(WITHOUT_MIDI)
	@${ECHO_MSG} "You can disable support for midi by defining WITHOUT_MIDI."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(includedir)/SDL|$$(includedir)/SDL11|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
