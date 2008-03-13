# New ports collection makefile for:	sdl_mixer
# Date created:				24 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.8
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	mva@sysfault.org
COMMENT=	A sample multi-channel audio mixer library

USE_AUTOTOOLS=	libtool:15
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CPPFLAGS+=	-DCONFIG_FILE_ETC_TIMIDITY \"${LOCALBASE}/etc/timidity.cfg\"
USE_LDCONFIG=	yes

OPTIONS=	MIKMOD		"Enable MOD music via libMikMod"	On \
		SMPEG		"Enable MP3 music via SMPEG"		On \
		VORBIS		"Enable Ogg Vorbis music"		On

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MIKMOD)
CONFIGURE_ARGS+=--disable-music-libmikmod
.else
LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod
CONFIGURE_ARGS+=--enable-music-libmikmod
.endif

.if defined(WITHOUT_SMPEG)
CONFIGURE_ARGS+=--disable-music-mp3
.else
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
CONFIGURE_ARGS+=--enable-music-mp3
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-music-ogg
.else
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-music-ogg
.endif

.include <bsd.port.post.mk>
