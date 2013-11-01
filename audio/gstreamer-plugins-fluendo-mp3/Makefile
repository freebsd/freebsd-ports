# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer-plugins-fluendo-mp3
PORTVERSION=	0.10.20
CATEGORIES=	audio
MASTER_SITES=	http://core.fluendo.com/gstreamer/src/gst-fluendo-mp3/
DISTNAME=	gst-fluendo-mp3-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Mp3 gstreamer plugin from fluendo

LICENSE=	MIT

CFLAGS:=	${CFLAGS} -O2
USES=		pkgconfig
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	lib/gstreamer-0.10/libgstflump3dec.la \
		lib/gstreamer-0.10/libgstflump3dec.so

.include <bsd.port.mk>
