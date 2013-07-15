# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	generator
PORTVERSION=	0.35.r4
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/cbiere/generator/
PKGNAMESUFFIX=	-cbiere
DISTNAME=	${PORTNAME}-0.35${PKGNAMESUFFIX}-r4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Genesis emulator

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS SDL
OPTIONS_DEFINE_i386=	RAZE
RAZE_DESC=	Use RAZE z80 emulation (only for i386)
SDL_DESC=	Use SDL for audio

USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=s/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/
CONFIGURE_ARGS+=--with-gtk
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}-gtk

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MOPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--without-gcc
.endif

.if ${PORT_OPTIONS:MRAZE}
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

.include <bsd.port.mk>
