# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/libsvg-cairo/Makefile,v 1.5 2005/08/09 04:49:38 ahze Exp $

PORTNAME=	libsvg-cairo
PORTVERSION=	0.1.6
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SVG rendering library

LIB_DEPENDS=	libsvg.so:graphics/libsvg \
		libcairo.so:graphics/cairo

GNU_CONFIGURE=	yes
USES=		jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes
PLIST_FILES=	include/svg-cairo.h \
		lib/libsvg-cairo.a \
		lib/libsvg-cairo.so \
		lib/libsvg-cairo.so.1 \
		lib/libsvg-cairo.so.1.0.1 \
		libdata/pkgconfig/libsvg-cairo.pc

.include <bsd.port.mk>
