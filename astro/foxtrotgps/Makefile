# Created by: crwhipp@gmail.com
# $FreeBSD$

PORTNAME=	foxtrotgps
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	astro geography
MASTER_SITES=	http://www.foxtrotgps.org/releases/

MAINTAINER=	crwhipp@gmail.com
COMMENT=	Lightweight opensource gps moving map application

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		exif:${PORTSDIR}/graphics/libexif \
		soup-2.4:${PORTSDIR}/devel/libsoup \
		gps:${PORTSDIR}/astro/gpsd

GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig shebangfix
SHEBANG_FILES=	contrib/convert2gpx \
		contrib/convert2osm \
		contrib/georss2foxtrotgps-poi

USE_GNOME=	gtk20 gconf2 libxml2 intltool libglade2
USE_SQLITE=	3
INSTALLS_ICONS=	yes

GCONF_SCHEMAS=	apps_foxtrotgps.schemas

MAN1=	foxtrotgps.1 convert2gpx.1 convert2osm.1

.include <bsd.port.mk>
