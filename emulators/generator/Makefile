# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	generator
PORTVERSION=	0.35
PORTREVISION=	12
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SEGA Genesis emulator

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

USE_GNOME=	gtk12
USE_SDL=	sdl
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-gtk

MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS RAZE SDL
RAZE_DESC=	Use RAZE z80 emulation (only for i386)
SDL_DESC=	Use SDL for audio

PLIST_FILES=	bin/${PORTNAME}-gtk

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CONFIGURE_ARGS+=--with-gcc=3
.else
CONFIGURE_ARGS+=--without-gcc
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
.if ${ARCH} != "amd64" && ${ARCH} != "i386"
# These architectures do not support "-minline-all-stringops"
	@${REINPLACE_CMD} -e 's|-minline-all-stringops||g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.   if ${ARCH} == "alpha"
# "-ffast-math" does not work on alpha
	@${REINPLACE_CMD} -e 's|-ffast-math||g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.   endif
.endif
	@${REINPLACE_CMD} -e '/%define %1 @UNDERSCORE@%1 /d' \
		${WRKSRC}/raze/raze.asm.in

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
