# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libexpat.so:${PORTSDIR}/textproc/expat2

USES+=		gettext:build
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

.include <bsd.port.options.mk>

# gcc from base can't handle some code in mesa 9.1+
# We only care for 9.x and 8.x, not for old pre-clang default current.
# This is for 0b0000 binary which gcc 4.3+ understands and is in the i965 driver.
.if defined(WITH_NEW_XORG)
. if ${OSVERSION} >= 901000 && ${OSVERSION} < 902502 \
		&& (${ARCH} == i386 || ${ARCH} == amd64)
CC=clang
CXX=clang++
CPP=clang-cpp
. elif ${OSVERSION} < 901500
USE_GCC=yes
. endif
.endif

.if ${ARCH} == ia64
#BROKEN=		does not install on ia64
.endif

ALL_DRI_DRIVERS=I915 I965 R200 RADEON SWRAST

.if !defined(WITH_NEW_XORG)
ALL_DRI_DRIVERS+=I810 MACH64 MGA R128 R300 R600 SAVAGE SIS TDFX UNICHROME
.endif

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

PLIST_SUB+=	VERSION=${MESADISTVERSION}

.if ${ARCH} == amd64 || ${ARCH} == i386
DRI_DRIVERS=	${ALL_DRI_DRIVERS}
.endif

.if defined(WITH_NEW_XORG)
. if defined(WITH_GALLIUM) && (${ARCH} == i386 || ${ARCH} == amd64)
BUILD_DEPENDS+=	llvm-config33:${PORTSDIR}/devel/llvm33
CONFIGURE_ENV+=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config33

CONFIGURE_ARGS+=--enable-gallium-llvm --disable-gallium-egl

CONFIGURE_ARGS+=--with-gallium-drivers=r300,r600,radeonsi,svga,swrast
PLIST_SUB+=	GALLIUM=""
. else
CONFIGURE_ARGS+=--enable-gallium-llvm=no --without-gallium-drivers
PLIST_SUB+=	GALLIUM="@comment "
. endif
. if ${ARCH} == powerpc || ${ARCH} == ia64
DRI_DRIVERS=	RADEON SWRAST
. endif
. if ${ARCH} == sparc64
DRI_DRIVERS=	SWRAST
. endif
.else # !defined(WITH_NEW_XORG)
. if ${ARCH} == powerpc
DRI_DRIVERS=	MACH64 RADEON SWRAST TDFX
. elif ${ARCH} == sparc64
DRI_DRIVERS=	MACH64 RADEON SWRAST
. endif
.endif # defined(WITH_NEW_XORG)

.for _d in ${ALL_DRI_DRIVERS}
.if ${DRI_DRIVERS:M${_d}}
PLIST_SUB+=	${_d}_DRIVER=""
.else
PLIST_SUB+=	${_d}_DRIVER="@comment "
.endif
.endfor

.if !(${ARCH} == amd64 || ${ARCH} == i386)
CONFIGURE_ARGS+=--disable-gallium-intel
.endif
CONFIGURE_ARGS+=--with-dri-drivers="${DRI_DRIVERS:L}"

.if defined(WITH_NEW_XORG) && !defined(WITH_GALLIUM) \
	&& (${ARCH} == i386 || ${ARCH} == amd64)
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For r300, r600, radeonsi and swrast gallium based drivers."
	@${ECHO_MSG} "Please define WITH_GALLIUM in /etc/make.conf"
	@${ECHO_MSG} "Note that gallium support is highly experimental."
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
