# New ports collection makefile for:   emulators/generator-cbiere
# Date created:        7 Jun 2005
# Whom:                Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	generator
PORTVERSION=	0.35.r4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/cbiere/generator/
PKGNAMESUFFIX=	-cbiere
DISTNAME=	${PORTNAME}-0.35${PKGNAMESUFFIX}-r4

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	SEGA Genesis emulator

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GMAKE=	yes
USE_GNOME=	gtk12

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		RAZE "Use RAZE z80 emulation (only for i386)" on \
		SDL_AUDIO "Use SDL for audio" off

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=s/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/
CONFIGURE_ARGS+=--with-gtk
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}-gtk

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--without-gcc
.endif

.if !defined(WITHOUT_RAZE) && ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=--with-raze
.else
CONFIGURE_ARGS+=--with-cmz80
.endif

.if defined(WITH_SDL_AUDIO)
CONFIGURE_ARGS+=--with-sdl-audio
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
