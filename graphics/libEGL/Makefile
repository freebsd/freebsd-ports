# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libEGL
PORTVERSION=	${MESAVERSION}
PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	OpenEGL library

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS+=	libexpat.so:textproc/expat2 \
		libdrm.so:graphics/libdrm

USE_GL=		gbm
USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libEGL but configure wants it
USE_XORG+=	dri2proto dri3proto glproto presentproto xdamage xext xfixes \
		xshmfence

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

MESA_BUILD_WRKSRC=	src/mapi src/gbm src/egl/
MESA_INSTALL_WRKSRC=	src/egl

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

.include <bsd.port.mk>
