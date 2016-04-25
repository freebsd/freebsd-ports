# Created by: crwhipp@gmail.com
# $FreeBSD$

PORTNAME=	foxtrotgps
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	http://www.foxtrotgps.org/releases/

MAINTAINER=	crwhipp@gmail.com
COMMENT=	Lightweight opensource gps moving map application

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexif.so:graphics/libexif \
		libsoup-2.4.so:devel/libsoup \
		libgps.so:astro/gpsd

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	DATADIRNAME=share
CONFIGURE_ARGS=	--disable-schemas-install
USES=		gettext gmake pkgconfig shebangfix sqlite:3
SHEBANG_FILES=	contrib/convert2gpx \
		contrib/convert2osm \
		contrib/georss2foxtrotgps-poi\
		contrib/gpx2osm

USE_GNOME=	gtk20 gconf2 libxml2 intltool libglade2
INSTALLS_ICONS=	yes

GCONF_SCHEMAS=	apps_foxtrotgps.schemas

.include <bsd.port.mk>
