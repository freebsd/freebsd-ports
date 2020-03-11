# Created by: crwhipp@gmail.com
# $FreeBSD$

PORTNAME=	foxtrotgps
PORTVERSION=	1.2.0
PORTREVISION=	6
CATEGORIES=	astro geography
MASTER_SITES=	http://www.foxtrotgps.org/releases/

MAINTAINER=	crwhipp@gmail.com
COMMENT=	Lightweight opensource gps moving map application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexif.so:graphics/libexif \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsoup-2.4.so:devel/libsoup \
		libgps.so:astro/gpsd

INFO=		foxtrotgps
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	DATADIRNAME=share
CONFIGURE_ARGS=	--disable-schemas-install
USES=		compiler:c++11-lang gettext gmake gnome pkgconfig python \
		shebangfix sqlite:3
SHEBANG_FILES=	contrib/convert2gpx \
		contrib/convert2osm \
		contrib/georss2foxtrotgps-poi\
		contrib/gpx2osm \
		contrib/poi2osm \
		contrib/osb2foxtrot \

USE_GNOME=	gtk20 gconf2 libxml2 intltool libglade2
INSTALLS_ICONS=	yes

GCONF_SCHEMAS=	apps_foxtrotgps.schemas

.include <bsd.port.mk>
