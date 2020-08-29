# Created by: crwhipp@gmail.com
# $FreeBSD$

PORTNAME=	foxtrotgps
PORTVERSION=	1.2.2
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
		libgps.so:astro/gpsd \
		libsoup-2.4.so:devel/libsoup

USES=		compiler:c++11-lang gettext gmake gnome pkgconfig python \
		shebangfix sqlite:3
USE_GNOME=	cairo gconf2 gtk20 intltool libglade2 libxml2
GLIB_SCHEMAS=	org.foxtrotgps.gschema.xml
INSTALLS_ICONS=	yes

SHEBANG_FILES=	contrib/convert2gpx \
		contrib/convert2osm \
		contrib/georss2foxtrotgps-poi\
		contrib/gpx2osm \
		contrib/osb2foxtrot \
		contrib/poi2osm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-schemas-install
CONFIGURE_ENV=	DATADIRNAME=share

INFO=		foxtrotgps

.include <bsd.port.mk>
