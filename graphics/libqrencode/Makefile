# ex:ts=8
# Ports collection makefile for:	libqrencode
# Date created:			Dec 14, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libqrencode
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://megaui.net/fukuchi/works/qrencode/
DISTNAME=	qrencode-${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	A C library for encoding data in a QR Code symbol

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GETOPT_LONG=	yes
USE_GNOME=	gnometarget gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

PLIST_FILES=	bin/qrencode \
		include/qrencode.h \
		lib/libqrencode.so \
		lib/libqrencode.so.1 \
		libdata/pkgconfig/libqrencode.pc

.include <bsd.port.mk>
