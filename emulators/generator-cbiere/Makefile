# New ports collection makefile for:   emulators/generator-cbiere
# Date created:        7 Jun 2005
# Whom:                Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	generator
PORTVERSION=	0.35.r2
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.ghostwhitecrab.com/generator/ \
		http://www.ghostwhitecrab.de/generator/
PKGNAMESUFFIX=	-cbiere
DISTNAME=	${PORTNAME}-0.35${PKGNAMESUFFIX}-r2

MAINTAINER=	alejandro@varnet.biz
COMMENT=	SEGA Genesis emulator

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GMAKE=	yes
USE_GNOME=	gtk12

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		RAZE "Use RAZE z80 emulation (only for i386)" on \
		SDL_AUDIO "Use SDL for audio" off

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=s/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/
CONFIGURE_ARGS+=	--with-gtk
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}-gtk

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--without-gcc
.endif

.if defined(WITH_RAZE) && ${ARCH} == "i386"
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=	--with-raze
.else
CONFIGURE_ARGS+=	--with-cmz80
.endif

.if defined(WITH_SDL_AUDIO)
CONFIGURE_ARGS+=	--with-sdl-audio
.endif

.include <bsd.port.post.mk>
