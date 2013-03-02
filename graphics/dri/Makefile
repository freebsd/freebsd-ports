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

OPTIONS_DEFINE=	I810 I915 I965 MACH64 MGA R128 R200 R300 R600 RADEON \
		SAVAGE SIS SWRAST TDFX UNICHROME

OPTIONS_DEFAULT=I810 I915 I965 MACH64 MGA R128 R200 R300 R600 RADEON \
		SAVAGE SIS SWRAST TDFX UNICHROME

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

do-install:
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-dri

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not install on ia64
.endif

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER=""
PLIST_SUB+=	MACH64_DRIVER=""
PLIST_SUB+=	MGA_DRIVER=""
PLIST_SUB+=	NOUVEAU_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	SAVAGE_DRIVER=""
PLIST_SUB+=	SIS_DRIVER=""
PLIST_SUB+=	SWRAST_DRIVER=""
PLIST_SUB+=	TDFX_DRIVER=""
PLIST_SUB+=	UNICHROME_DRIVER=""
.endif

.if ${ARCH} == "arm"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER="@comment "
PLIST_SUB+=	MACH64_DRIVER="@comment "
PLIST_SUB+=	MGA_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
PLIST_SUB+=	SAVAGE_DRIVER="@comment "
PLIST_SUB+=	SIS_DRIVER="@comment "
PLIST_SUB+=	SWRAST_DRIVER="@comment "
PLIST_SUB+=	TDFX_DRIVER="@comment "
PLIST_SUB+=	UNICHROME_DRIVER="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	I810_DRIVER=""
PLIST_SUB+=	I9X5_DRIVER=""
PLIST_SUB+=	MACH64_DRIVER=""
PLIST_SUB+=	MGA_DRIVER=""
PLIST_SUB+=	NOUVEAU_DRIVER=""
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	SAVAGE_DRIVER=""
PLIST_SUB+=	SIS_DRIVER=""
PLIST_SUB+=	SWRAST_DRIVER=""
PLIST_SUB+=	TDFX_DRIVER=""
PLIST_SUB+=	UNICHROME_DRIVER=""
.endif

.if ${ARCH} == "mips"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER="@comment "
PLIST_SUB+=	MACH64_DRIVER="@comment "
PLIST_SUB+=	MGA_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS="@comment "
PLIST_SUB+=	SAVAGE_DRIVER="@comment "
PLIST_SUB+=	SIS_DRIVER="@comment "
PLIST_SUB+=	SWRAST_DRIVER="@comment "
PLIST_SUB+=	TDFX_DRIVER="@comment "
PLIST_SUB+=	UNICHROME_DRIVER="@comment "
.endif

.if ${ARCH} == "powerpc"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER="@comment "
PLIST_SUB+=	MACH64_DRIVER=""
PLIST_SUB+=	MGA_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	SAVAGE_DRIVER="@comment "
PLIST_SUB+=	SIS_DRIVER="@comment "
PLIST_SUB+=	SWRAST_DRIVER=""
PLIST_SUB+=	TDFX_DRIVER=""
PLIST_SUB+=	UNICHROME_DRIVER="@comment "
.endif

.if ${ARCH} == "sparc64"
PLIST_SUB+=	I810_DRIVER="@comment "
PLIST_SUB+=	I9X5_DRIVER="@comment "
PLIST_SUB+=	MACH64_DRIVER=""
PLIST_SUB+=	MGA_DRIVER="@comment "
PLIST_SUB+=	NOUVEAU_DRIVER="@comment "
PLIST_SUB+=	RADEON_DRIVERS=""
PLIST_SUB+=	SAVAGE_DRIVER="@comment "
PLIST_SUB+=	SIS_DRIVER="@comment "
PLIST_SUB+=	SWRAST_DRIVER=""
PLIST_SUB+=	TDFX_DRIVER="@comment "
PLIST_SUB+=	UNICHROME_DRIVER="@comment "
.endif

ALL_DRI_DRIVERS=	i810 i915 i965 mach64 mga r128 r200 r300 r600 radeon \
			savage sis swrast tdfx unichrome

.for _d in ${ALL_DRI_DRIVERS}
.if ${PORT_OPTIONS:M${_d:U}}
DRI_DRIVERS+=	,${_d}
PLIST_SUB+=	${_d:U}=""
. else
PLIST_SUB+=	${_d:U}="@comment "
. endif
.endfor
CONFIGURE_ARGS+=	--with-dri-drivers="${DRI_DRIVERS:C/,//1}"

.include <bsd.port.post.mk>
