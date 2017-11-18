# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mesa-demos
PORTVERSION=	8.3.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/demos/${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa

LICENSE=	MIT

LIB_DEPENDS=	libdrm.so:graphics/libdrm

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig tar:bzip2
USE_GL=		egl gbm gl glesv2 glew glu glut
USE_XORG=	dri2proto glproto x11 xdamage xext xfixes xi xxf86vm

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--disable-osmesa --disable-vg --disable-wayland \
		--with-system-data-files

.include <bsd.port.mk>
