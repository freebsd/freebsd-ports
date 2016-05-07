# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	generator
PORTVERSION=	0.35
PORTREVISION=	15
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Genesis emulator

LICENSE=	GPLv2

USES=		gmake jpeg
USE_GNOME=	gtk12
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}-gtk

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS SDL
OPTIONS_DEFINE_i386=	RAZE

OPTIMIZED_CFLAGS_CONFIGURE_ON=	--with-gcc=3
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

.include <bsd.port.pre.mk>

post-patch:
.if ${ARCH} != "amd64" && ${ARCH} != "i386"
# These architectures do not support "-minline-all-stringops"
	@${REINPLACE_CMD} -e \
		's|-minline-all-stringops||g' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e \
		'/%define %1 @UNDERSCORE@%1 /d' ${WRKSRC}/raze/raze.asm.in

.include <bsd.port.post.mk>
