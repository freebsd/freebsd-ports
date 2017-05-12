# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mesa-dri
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for DRI2+

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2
RUN_DEPENDS=	${LOCALBASE}/lib/libtxc_dxtn.so:graphics/s2tc

USE_XORG=	dri2proto dri3proto glproto presentproto x11 xdamage xext \
		xfixes xshmfence xv xvmc

OPTIONS_DEFINE=	TEXTURE VAAPI VDPAU
OPTIONS_DEFAULT=TEXTURE
OPTIONS_SUB=	yes
PKGHELP=	${.CURDIR}/pkg-help

TEXTURE_DESC=	Enable texture-float support (patent encumbered)
TEXTURE_CONFIGURE_ENABLE=	texture-float

VAAPI_CONFIGURE_ENABLE=	va
VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_USE=		XORG=xcb

VDPAU_CONFIGURE_ENABLE=	vdpau
VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/mesa-dri/Makefile.common"

ALL_DRI_DRIVERS=	I915 I965 RADEON R200 SWRAST
ALL_GALLIUM_DRIVERS=	FREEDRENO R300 R600 RADEONSI SVGA SWRAST VC4

DRI_DRIVERS=		SWRAST
GALLIUM_DRIVERS=	SWRAST
.if ${ARCH} == amd64 || ${ARCH} == i386 \
 || ${ARCH} == powerpc || ${ARCH} == powerpc64
DRI_DRIVERS+=		RADEON R200
GALLIUM_DRIVERS+=	R300 R600 RADEONSI
.elif ${ARCH} == armv6 || ${ARCH} == aarch64
GALLIUM_DRIVERS+=	FREEDRENO VC4
.endif
.if ${ARCH} == amd64 || ${ARCH} == i386
DRI_DRIVERS+=		I915 I965
GALLIUM_DRIVERS+=	SVGA
.endif

CONFIGURE_ARGS+=	--with-dri-drivers="${DRI_DRIVERS:tl}" \
			--with-gallium-drivers="${GALLIUM_DRIVERS:tl}"

.for _d in ${ALL_DRI_DRIVERS}
. if ${DRI_DRIVERS:M${_d}}
PLIST_SUB+=	${_d}_DRIVER=""
. else
PLIST_SUB+=	${_d}_DRIVER="@comment "
. endif
.endfor

.for _gd in ${ALL_GALLIUM_DRIVERS}
. if ${GALLIUM_DRIVERS:M${_gd}}
PLIST_SUB+=	${_gd}_GDRIVER=""
. else
PLIST_SUB+=	${_gd}_GDRIVER="@comment "
. endif
.endfor

.include "${.CURDIR}/../../graphics/mesa-dri/Makefile.targets"

post-install:
	@${RM} -r ${STAGEDIR}/etc/OpenCL

.include <bsd.port.mk>
