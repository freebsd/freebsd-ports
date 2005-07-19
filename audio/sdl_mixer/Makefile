# New ports collection makefile for:	sdl_mixer
# Date created:				24 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	A sample multi-channel audio mixer library

USE_SDL=	sdl
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
INSTALLS_SHLIB=	yes

OPTIONS=	MIKMOD "Enable MOD music via libMikMod" on \
		VORBIS "Enable Ogg Vorbis music" on \
		SMPEG "Enable MP3 music via SMPEG" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MIKMOD)
CONFIGURE_ARGS+=	--disable-music-libmikmod
.else
LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--disable-music-ogg
.else
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITHOUT_SMPEG)
CONFIGURE_ARGS+=	--disable-music-mp3
.else
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
.endif

.include <bsd.port.post.mk>
