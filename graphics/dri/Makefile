# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2

USES=		ssl
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto \
		presentproto xvmc xshmfence

OPTIONS_DEFINE=	TEXTURE
OPTIONS_DEFAULT=TEXTURE

TEXTURE_DESC=	Enable texture-float support (patent encumbered)
VDPAU_DESC=	VDPAU (GPU video acceleration) support (needs Gallium)

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
