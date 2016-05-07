# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	generator
PORTVERSION=	0.35.r4
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/cbiere/generator/
PKGNAMESUFFIX=	-cbiere
DISTNAME=	${PORTNAME}-0.35${PKGNAMESUFFIX}-r4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Genesis emulator

LICENSE=	GPLv2

USES=		gmake jpeg tar:bzip2
USE_GNOME=	gtk12
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=s/${PORTNAME}/${PORTNAME}/ \
		--with-gtk
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}-gtk

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS SDL
OPTIONS_DEFINE_i386=	RAZE

OPTIMIZED_CFLAGS_CONFIGURE_OFF=	--without-gcc
RAZE_DESC=		Use RAZE z80 emulation
RAZE_BUILD_DEPENDS=	nasm:devel/nasm
RAZE_CONFIGURE_ON=	--with-raze
SDL_DESC=		Use SDL for audio
SDL_CONFIGURE_ON=	--with-sdl-audio

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MRAZE)
CONFIGURE_ARGS+=--with-cmz80
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/%define %1 @UNDERSCORE@%1 /d' ${WRKSRC}/raze/raze.asm.in

.include <bsd.port.mk>
