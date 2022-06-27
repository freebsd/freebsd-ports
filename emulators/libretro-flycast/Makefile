# Created by: Timothy Beyer <beyert@cs.ucr.edu>

PORTNAME=	libretro-flycast
PORTVERSION=	0.20210608
PORTREVISION=	1
CATEGORIES=	emulators games

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Standalone port of flycast to libretro

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS+=	libao.so:audio/libao \
		libasound.so:audio/alsa-lib \
		libcurl.so:ftp/curl \
		libevdev.so:devel/libevdev \
		libpulse.so:audio/pulseaudio \
		libudev.so:devel/libudev-devd \
		libvulkan.so:graphics/vulkan-loader

USES=	compiler:c++11-lib dos2unix gl gmake pkgconfig xorg
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libretro
GH_PROJECT=	flycast
GH_TAGNAME=	8e4fa54e

USE_GL+=	egl gl glew glu

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

DOS2UNIX_FILES=	core/hw/bba/rtl8139c.h

.if ${ARCH} == amd64
CFLAGS+=	-DLOW_END
CXXFLAGS+=	-DLOW_END
.endif

LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	HAVE_GENERIC_JIT=0 \
		HAVE_VULKAN=0

.if ${ARCH} == amd64
MAKE_ARGS+=	WITH_DYNAREC=x86_64
.elif ${ARCH} == i386
MAKE_ARGS+=	WITH_DYNAREC=x86
USE_BINUTILS=	yes
LDFLAGS+=	-Wl,-z,notext
.endif

PLIST_FILES=	lib/libretro/flycast_libretro.so

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKSRC}/flycast_libretro.so \
		${STAGEDIR}/${PREFIX}/lib/libretro/flycast_libretro.so;

.include <bsd.port.post.mk>
