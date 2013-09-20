# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm \
		expat:${PORTSDIR}/textproc/expat2

USES=		pkgconfig
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

ALL_DRI_DRIVERS=I915 I965 R200 RADEON SWRAST

.if ! defined(WITH_NEW_XORG)
ALL_DRI_DRIVERS+=I810 MACH64 MGA R128 R300 R600 SAVAGE SIS TDFX UNICHROME
.endif

NO_STAGE=	yes
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

OPTIONS_DEFINE_i386=	${ALL_DRI_DRIVERS}
OPTIONS_DEFINE_amd64=	${OPTIONS_DEFINE_i386}

.if defined(WITH_NEW_XORG)
OPTIONS_DEFINE_powerpc=	RADEON SWRAST
OPTIONS_DEFINE_sparc64=	RADEON SWRAST
.else
OPTIONS_DEFINE_powerpc=	MACH64 RADEON SWRAST TDFX
OPTIONS_DEFINE_sparc64=	MACH64 RADEON SWRAST
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
RADEON_DESC=	Include DRI support for AMD/ATI RADEON
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

.if ${ARCH} == "ia64"
BROKEN=		does not install on ia64
.endif

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif
CONFIGURE_ARGS+=--with-dri-drivers="${DRI_DRIVERS:L}"

do-install:
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-dri

.include <bsd.port.mk>
