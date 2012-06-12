# New ports collection makefile for:   emulators/generator-cbiere
# Date created:        7 Jun 2005
# Whom:                Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	generator
PORTVERSION=	0.35.r4
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/cbiere/generator/
PKGNAMESUFFIX=	-cbiere
DISTNAME=	${PORTNAME}-0.35${PKGNAMESUFFIX}-r4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Genesis emulator

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GMAKE=	yes
USE_GNOME=	gtk12
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS RAZE SDL
RAZE_DESC=	Use RAZE z80 emulation (only for i386)
SDL_DESC=	Use SDL for audio

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=s/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/
CONFIGURE_ARGS+=--with-gtk
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}-gtk

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MOPTIIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--without-gcc
.endif

.if ${PORT_OPTIONS:MRAZE} && ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=--with-raze
.else
CONFIGURE_ARGS+=--with-cmz80
.endif

.if ${PORT_OPTIONS:MSDL}
CONFIGURE_ARGS+=--with-sdl-audio
.endif

post-patch:
	@${REINPLACE_CMD} -e '/%define %1 @UNDERSCORE@%1 /d' \
		${WRKSRC}/raze/raze.asm.in

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
