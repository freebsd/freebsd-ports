# New ports collection makefile for:	sdl_sound
# Date created:				6 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	sdl_sound
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.icculus.org/SDL_sound/downloads/
DISTNAME=	SDL_sound-1.0.0

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A SDL audio library and player for some popular sound file formats

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|^program_transform_name.+$$||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -E -e \
		's|\$$\(includedir\)/SDL|\$$(includedir)/SDL11|' \
		${CONFIGURE_WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FLAC)
LIB_DEPENDS+=	FLAC.5:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !defined(WITHOUT_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=	--disable-mikmod
.endif

.if !defined(WITHOUT_SMPEG)
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
.else
CONFIGURE_ARGS+=	--disable-smpeg
.endif

.if !defined(WITHOUT_MIDI)
RUN_DEPENDS+=	${LOCALBASE}/lib/timidity/goemon.cfg:${PORTSDIR}/audio/timidity
BUILD_DEPENDS+=	${LOCALBASE}/lib/timidity/goemon.cfg:${PORTSDIR}/audio/timidity
.else
CONFIGURE_ARGS+=	--disable-midi
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis
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
.if !defined(WITHOUT_SMPEG)
	@${ECHO_MSG} "You can disable support for smpeg by defining WITHOUT_SMPEG."
.endif
.if !defined(WITHOUT_MIDI)
	@${ECHO_MSG} "You can disable support for midi by defining WITHOUT_MIDI."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS."
.endif

.include <bsd.port.post.mk>
