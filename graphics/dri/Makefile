# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm \
		expat.6:${PORTSDIR}/textproc/expat2

USE_PKGCONFIG=	build
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

ALL_DRI_DRIVERS=I810 I915 I965 MACH64 MGA R128 R200 R300 R600 RADEON \
		SAVAGE SIS SWRAST TDFX UNICHROME

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.if ${ARCH} == "ia64"
BROKEN=		does not install on ia64
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
OPTIONS_DEFINE=	${ALL_DRI_DRIVERS}
.elif ${ARCH} == "powerpc"
OPTIONS_DEFINE=	MACH64 RADEON SWRAST TDFX
.elif ${ARCH} == "sparc64"
OPTIONS_DEFINE=	MACH64 RADEON SWRAST
.endif
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

I810_DESC=	Include DRI support for Intel i810
I915_DESC=	Include DRI support for Intel i915
I965_DESC=	Include DRI support for Intel i965
MACH64_DESC=	Include DRI support for AMD/ATI Mach64
MGA_DESC=	Include DRI support for Matrox
R128_DESC=	Include DRI support for AMD/ATI R128
R200_DESC=	Include DRI support for AMD/ATI R200
R300_DESC=	Include DRI support for AMD/ATI R300
R600_DESC=	Include DRI support for AMD/ATI R600
RADEON_DESC=	Include DRI support for AMD/ATI R100
SAVAGE_DESC=	Include DRI support for S3/Via Savage
SIS_DESC=	Include DRI support for SiS 300 and 6326
SWRAST_DESC=	Include generic software DRI support
TDFX_DESC=	Include DRI support for 3dfx Voodoo
UNICHROME_DESC=	Include DRI support for S3/Via Unichrome

.include <bsd.port.options.mk>

DRI_DRIVERS=
.for _d in ${ALL_DRI_DRIVERS}
.if ${PORT_OPTIONS:M${_d}}
DRI_DRIVERS+=	${_d}
PLIST_SUB+=	${_d}_DRIVER=""
.else
PLIST_SUB+=	${_d}_DRIVER="@comment "
.endif
.endfor

.include <bsd.port.pre.mk>

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif
CONFIGURE_ARGS+=--with-dri-drivers="${DRI_DRIVERS:L}"

do-install:
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-dri

.include <bsd.port.post.mk>
