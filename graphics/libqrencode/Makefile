# ex:ts=8
# Ports collection makefile for:	libqrencode
# Date created:			Dec 14, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libqrencode
PORTVERSION=	3.1.0
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://megaui.net/fukuchi/works/qrencode/
DISTNAME=	qrencode-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A C library for encoding data in a QR Code symbol

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnometarget gnomehack pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

MAN1=		qrencode.1

PLIST_FILES=	bin/qrencode \
		include/qrencode.h \
		lib/libqrencode.la \
		lib/libqrencode.so \
		lib/libqrencode.so.3 \
		libdata/pkgconfig/libqrencode.pc

.include <bsd.port.mk>
