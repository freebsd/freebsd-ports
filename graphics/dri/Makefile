# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2

USE_XORG=	dri2proto dri3proto glproto presentproto x11 xdamage xext \
		xfixes xshmfence xv xvmc xxf86vm 

OPTIONS_DEFINE=	TEXTURE VAAPI VDPAU
OPTIONS_DEFAULT=TEXTURE
OPTIONS_SUB=	yes

TEXTURE_DESC=	Enable texture-float support (patent encumbered)
TEXTURE_CONFIGURE_ENABLE=	texture-float

VAAPI_CONFIGURE_ENABLE=	va
VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_USE=		XORG=xcb

VDPAU_CONFIGURE_ENABLE=	vdpau
VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau

PKGHELP=	${.CURDIR}/pkg-help

.include <bsd.port.options.mk>

.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

#src/mesa/libmesagallium.la
#MESA_BUILD_WRKSRC=	src/util src/gallium
#MESA_INSTALL_WRKSRC=	src/gallium

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${RM} -r ${STAGEDIR}/etc/OpenCL

.include <bsd.port.mk>
