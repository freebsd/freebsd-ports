# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	gbm
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	gbm library

LIB_DEPENDS+=	libpthread-stubs.so:devel/libpthread-stubs \
		libexpat.so:textproc/expat2 \
		libdrm.so:graphics/libdrm \
		libglapi.so:graphics/libglapi

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by gbm but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes presentproto \
		xshmfence

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

MESA_BUILD_WRKSRC=	src/mapi src/gbm
MESA_INSTALL_WRKSRC=	src/gbm

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

.include <bsd.port.mk>
