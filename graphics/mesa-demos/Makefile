# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mesa-demos
PORTVERSION=	8.3.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/demos/${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig tar:bzip2
USE_GL=		glew glu glut
USE_XORG=	dri2proto glproto x11 xdamage xext xfixes xi xxf86vm

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--disable-egl --disable-gbm --disable-gles2 \
		--disable-osmesa --disable-vg --disable-wayland \
		--with-system-data-files --disable-freetype2

.include <bsd.port.mk>
