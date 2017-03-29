# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	gbm
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	gbm library

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS+=	libexpat.so:textproc/expat2 \
		libdrm.so:graphics/libdrm \
		libglapi.so:graphics/libglapi

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by gbm but configure wants it
USE_XORG+=	dri2proto dri3proto glproto presentproto xdamage xext xfixes \
		xshmfence

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

MESA_BUILD_WRKSRC=	src/mapi src/gbm
MESA_INSTALL_WRKSRC=	src/gbm

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

.include <bsd.port.mk>
