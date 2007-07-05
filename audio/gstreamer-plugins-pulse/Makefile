# New ports collection makefile for:	gstreamer-plugins-pulse
# Date created:		July 22, 2006
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer-plugins
PORTVERSION=	0.9.4
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/gst-pulse/
PKGNAMESUFFIX=	-pulse
DISTNAME=	gst${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plugin for pulseaudio

LIB_DEPENDS=	pulse.0:${PORTSDIR}/audio/pulseaudio

CFLAGS:=	${CFLAGS} -O2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	lthack gnomehack
USE_GSTREAMER=	yes
CONFIGURE_ARGS=	--disable-lynx
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	lib/gstreamer-0.10/libgstpulse.a \
		lib/gstreamer-0.10/libgstpulse.la \
		lib/gstreamer-0.10/libgstpulse.so \
		lib/gstreamer-0.10/libgstpulse.so.0

.include <bsd.port.mk>
