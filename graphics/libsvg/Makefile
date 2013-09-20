# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$
#   $MCom: ports/graphics/libsvg/Makefile,v 1.3 2005/07/04 00:11:29 marcus Exp $

PORTNAME=	libsvg
PORTVERSION=	0.1.4
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A parser for SVG content in files or buffers

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USES=		pathfix iconv pkgconfig
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	include/svg.h \
		lib/libsvg.a \
		lib/libsvg.la \
		lib/libsvg.so \
		lib/libsvg.so.1 \
		libdata/pkgconfig/libsvg.pc

NO_STAGE=	yes
.include <bsd.port.mk>
