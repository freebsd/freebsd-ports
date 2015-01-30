# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${DRIREVISION}
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libexpat.so:${PORTSDIR}/textproc/expat2

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto \
		presentproto xvmc xshmfence

OPTIONS_DEFINE=	TEXTURE
OPTIONS_DEFAULT=TEXTURE

OPTIONS_DEFINE_i386=	GALLIUM
OPTIONS_DEFAULT_i386=	GALLIUM
OPTIONS_DEFINE_amd64=	GALLIUM
OPTIONS_DEFAULT_amd64=	GALLIUM

GALLIUM_DESC=	Gallium (llvm backed) dri drivers
TEXTURE_DESC=	Enable texture-float support (patent encumbered)
VDPAU_DESC=	VDPAU (GPU video acceleration) support (needs Gallium)

PKGHELP=	${.CURDIR}/pkg-help

.include <bsd.port.options.mk>

# gcc from base can't handle some code in mesa 9.1+
# We only care for 9.x and 8.x. clang in 10.x is new enough.
# This is for 0b0000 binary which gcc 4.3+ understands and is in the i965 driver.
. if (${OSVERSION} >= 901500 && ${OSVERSION} < 1000000)
CC=clang
CXX=clang++
CPP=clang-cpp
. elif ${OSVERSION} < 901500
USE_GCC=yes
. endif

ALL_DRI_DRIVERS=I915 I965 R200 RADEON SWRAST

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

PLIST_SUB+=	VERSION=${MESADISTVERSION}

.if ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == ia64
DRI_DRIVERS=	${ALL_DRI_DRIVERS}
.endif

.if defined(WITH_NEW_MESA)
DRIREVISION=	0
PLIST=	${.CURDIR}/pkg-plist
.else
DRIREVISION=	6
PLIST=	${.CURDIR}/pkg-plist-old
.endif

.if ${PORT_OPTIONS:MGALLIUM}
BUILD_DEPENDS+=	llvm${MESA_LLVM_VER}>=0:${PORTSDIR}/devel/llvm${MESA_LLVM_VER}
RUN_DEPENDS+=	llvm${MESA_LLVM_VER}>=0:${PORTSDIR}/devel/llvm${MESA_LLVM_VER}
CONFIGURE_ENV+=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${MESA_LLVM_VER}

CONFIGURE_ARGS+=--enable-gallium-llvm \
		--enable-xvmc \
		--with-gallium-drivers=r300,r600,radeonsi,svga,swrast
PLIST_SUB+=	GALLIUM=""
.else
CONFIGURE_ARGS+=--enable-gallium-llvm=no --without-gallium-drivers \
		--disable-gallium-egl
PLIST_SUB+=	GALLIUM="@comment "
.endif

.if ${PORT_OPTIONS:MTEXTURE}
CONFIGURE_ARGS+=--enable-texture-float
.endif

.if 0 #${PORT_OPTIONS:MVDPAU}
.if ${PORT_OPTIONS:MGALLIUM} == ""
IGNORE=	VDPAU option requires GALLIUM support to be enabled
.endif
CONFIGURE_ARGS+=--enable-vdpau
LIB_DEPENDS+=	libvdpau.so:${PORTSDIR}/multimedia/libvdpau
PLIST_SUB+=	VDPAU=""
.else
CONFIGURE_ARGS+=--disable-vdpau
PLIST_SUB+=	VDPAU="@comment "
.endif

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
DRI_DRIVERS=	RADEON SWRAST
.endif
.if ${ARCH} == sparc64 || ${ARCH} == armv6
DRI_DRIVERS=	SWRAST
.endif

# empty for unsupported arches
DRI_DRIVERS+=

.for _d in ${ALL_DRI_DRIVERS}
. if ${DRI_DRIVERS:M${_d}}
PLIST_SUB+=	${_d}_DRIVER=""
. else
PLIST_SUB+=	${_d}_DRIVER="@comment "
. endif
.endfor

.if !(${ARCH} == amd64 || ${ARCH} == i386)
CONFIGURE_ARGS+=--disable-gallium-intel
.endif
CONFIGURE_ARGS+=--with-dri-drivers="${DRI_DRIVERS:tl}"

.include <bsd.port.mk>
