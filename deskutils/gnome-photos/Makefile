# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-photos
PORTVERSION=	3.24.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photo application for GNOME 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	geoclue>=0:net/geoclue \
		itstool:textproc/itstool
LIB_DEPENDS=	libexempi.so:textproc/exempi \
		libgfbgraph-0.2.so:net/gfbgraph \
		libgegl-0.3.so:graphics/gegl3 \
		libgrilo-0.3.so:net/grilo \
		libexiv2.so:graphics/exiv2 \
		libgexiv2.so:graphics/gexiv2 \
		libtracker-control-1.0.so:sysutils/tracker \
		libgeocode-glib.so:net/geocode-glib \
		libgjs.so:lang/gjs \
		libbabl-0.1.so:x11/babl \
		librest-0.7.so:devel/librest \
		libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libgoa-1.0.so:net/gnome-online-accounts \
		libpng16.so:graphics/png \
		libgdata.so:devel/libgdata
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gmake gnome jpeg libtool \
		localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gnomedesktop3 gtk30 intlhack libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.photos.gschema.xml

.include <bsd.port.mk>
