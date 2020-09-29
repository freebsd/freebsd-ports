# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-photos
PORTVERSION=	3.38.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photo application for GNOME 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	geoclue>=0:net/geoclue \
		itstool:textproc/itstool
LIB_DEPENDS=	libexempi.so:textproc/exempi \
		libfribidi.so:converters/fribidi \
		libgfbgraph-0.2.so:net/gfbgraph \
		libgegl-0.4.so:graphics/gegl \
		libgrilo-0.3.so:net/grilo \
		libexiv2.so:graphics/exiv2 \
		libgexiv2.so:graphics/gexiv2 \
		libtracker-control-2.0.so:sysutils/tracker \
		libgeocode-glib.so:net/geocode-glib \
		libgjs.so:lang/gjs \
		libbabl-0.1.so:x11/babl \
		librest-0.7.so:devel/librest \
		libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libgoa-1.0.so:net/gnome-online-accounts \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libpng.so:graphics/png \
		libgdata.so:devel/libgdata
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome jpeg localbase meson pkgconfig tar:xz
USE_GNOME=	cairo gnomedesktop3 gtk30 libxml2
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.photos.gschema.xml
MESON_ARGS=	--buildtype plain

.include <bsd.port.mk>
