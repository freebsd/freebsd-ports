# New ports collection makefile for: 	gphoto
# Version required:	gphoto-19990511
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

DISTNAME=	gphoto-0.3.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.mustec.eu.org/~psj/downloads/ \
		http://www.freenix.no/~anders/

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	${X11BASE}/include/ppm.h:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gdk_imlib.5:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_LIBTOOL=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${PREFIX}/bin/glib12-config" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		IMLIB_CONFIG="${X11BASE}/bin/imlib-config" \

MAN1=		gphoto.1

ALL_TARGET=

.include <bsd.port.mk>
