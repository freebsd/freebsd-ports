# ex:ts=8
# Ports collection makefile for:	swfdec
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swfdec
PORTVERSION=	0.5.0
CATEGORIES=	graphics
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec/0.5/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		oil-0.3.1:${PORTSDIR}/devel/liboil

USE_XLIB=	yes
USE_GNOME=	gnomehack gtk20 gnomevfs2
USE_GSTREAMER=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-Wl,-Bsymbolic -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-audio=none
INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
