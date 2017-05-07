# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libEGL
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	OpenEGL library

LIB_DEPENDS+=	libpthread-stubs.so:devel/libpthread-stubs \
		libexpat.so:textproc/expat2 \
		libdevq.so:devel/libdevq \
		libdrm.so:graphics/libdrm

OPTIONS_DEFINE_amd64=	DRI3
OPTIONS_DEFINE_i386=	DRI3
DRI3_DESC=	Experimental: Enable DRI3 support.

USE_GL=		gbm
USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libEGL but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes presentproto \
		xshmfence dri3proto

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

MESA_BUILD_WRKSRC=	src/mapi src/egl/wayland/wayland-egl \
			src/egl/wayland/wayland-drm src/gbm src/egl
MESA_INSTALL_WRKSRC=	src/egl src/egl/wayland/wayland-egl

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/.mesa
	@${MV} ${STAGEDIR}${PREFIX}/lib/libEGL* \
		${STAGEDIR}${PREFIX}/lib/.mesa/

.include <bsd.port.mk>
