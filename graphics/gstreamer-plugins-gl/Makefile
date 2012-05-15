# New ports collection makefile for:	gstreamer-plugins-gl
# Date created:		6 Sep 2010
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer-plugins-gl
PORTVERSION=	0.10.3
CATEGORIES=	graphics
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-plugins-gl/
DISTNAME=	${PORTNAME:S/gstreamer/gst/}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer OpenGL video plugin

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack
USE_GSTREAMER=	yes
USE_XORG=	ice x11
USE_GL=		gl glu glew
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=--disable-examples

PLIST_SUB=	VERSION="0.10"

.include <bsd.port.mk>
