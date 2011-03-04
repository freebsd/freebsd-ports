# New ports collection makefile for:	foxtrotgps
# Date created:				15 January 2011
# Whom:						crwhipp
#
# $FreeBSD$
#

PORTNAME=	foxtrotgps
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	http://www.foxtrotgps.org/releases/

MAINTAINER=	crwhipp@gmail.com
COMMENT=	A lightweight opensource gps moving map application

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		exif.12:${PORTSDIR}/graphics/libexif \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gps.19:${PORTSDIR}/astro/gpsd

USE_AUTOTOOLS=	automake aclocal libtool autoconf
ACLOCAL_ARGS=	--force
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes

USE_GNOME=	gtk20 gconf2 libxml2 intltool pkgconfig libglade2
USE_SQLITE=	3
INSTALLS_ICONS=	yes

MAN1=	foxtrotgps.1 convert2gpx.1 convert2osm.1

.include <bsd.port.mk>
