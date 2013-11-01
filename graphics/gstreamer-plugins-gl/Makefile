# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer-plugins-gl
PORTVERSION=	0.10.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-plugins-gl/
DISTNAME=	${PORTNAME:S/gstreamer/gst/}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer OpenGL video plugin

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=	pathfix gettext gmake pkgconfig
USE_GSTREAMER=	yes
USE_XORG=	ice x11
USE_GL=		gl glu glew
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=--disable-examples

PLIST_SUB=	VERSION="0.10"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgstgl-0.10.so.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-0.10/libgst*.so

.include <bsd.port.mk>
