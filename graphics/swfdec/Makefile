# ex:ts=8
# Ports collection makefile for:	swfdec
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swfdec
PORTVERSION=	0.5.1
CATEGORIES=	graphics
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec/0.5/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		oil-0.3.1:${PORTSDIR}/devel/liboil \
		soup-2.2.8:${PORTSDIR}/devel/libsoup

USE_XLIB=	yes
USE_GNOME=	gnomehack gtk20
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-Wl,-Bsymbolic -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-audio=oss
INSTALLS_SHLIB=	yes

OPTIONS=	GSTREAMER "Support for decoding some codecs with GStreamer" off

PLIST_SUB=	VERSION=${PORTVERSION:R}

.if defined(WITH_GSTREAMER)
USE_GSTREAMER=	yes
.else
CONFIGURE_ARGS+= --disable-gstreamer
.endif

.include <bsd.port.mk>
