# New ports collection makefile for:	libsvg-cairo
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsvg-cairo
PORTVERSION=	0.1.5
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	SVG rendering library

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		svg.1:${PORTSDIR}/graphics/libsvg \
		cairo.1:${PORTSDIR}/graphics/cairo

USE_LIBTOOL_VER=15
USE_GNOME=	pkgconfig gnometarget gnomehack
INSTALLS_SHLIB=	yes
PLIST_FILES=	include/svg-cairo.h \
		lib/libsvg-cairo.a \
		lib/libsvg-cairo.so \
		lib/libsvg-cairo.so.1 \
		libdata/pkgconfig/libsvg-cairo.pc

.include <bsd.port.mk>
