# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libexpat.so:${PORTSDIR}/textproc/expat2

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto \
		presentproto xvmc xshmfence

OPTIONS_DEFINE=	TEXTURE
OPTIONS_DEFAULT=TEXTURE

TEXTURE_DESC=	Enable texture-float support (patent encumbered)
VDPAU_DESC=	VDPAU (GPU video acceleration) support (needs Gallium)

PKGHELP=	${.CURDIR}/pkg-help

.include <bsd.port.options.mk>

ALL_DRI_DRIVERS=I915 I965 R200 RADEON SWRAST

.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

#src/mesa/libmesagallium.la
#MESA_BUILD_WRKSRC=	src/util src/gallium
#MESA_INSTALL_WRKSRC=	src/gallium

PLIST_SUB+=	VERSION=${MESADISTVERSION}

.if ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == ia64
DRI_DRIVERS=	${ALL_DRI_DRIVERS}
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

CONFIGURE_ARGS+=--with-dri-drivers="${DRI_DRIVERS:tl}"

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${RM} -rf ${STAGEDIR}/etc/OpenCL

.include <bsd.port.mk>
