PORTNAME=	gnome-photos
DISTVERSION=	44.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photo application for GNOME
WWW=		https://wiki.gnome.org/Design/Apps/Photos

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	geoclue>=0:net/geoclue \
		itstool:textproc/itstool
LIB_DEPENDS=	libbabl-0.1.so:x11/babl \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libfribidi.so:converters/fribidi \
		libgegl-0.4.so:graphics/gegl \
		libgeocode-glib-2.so:net/geocode-glib2 \
		libgexiv2.so:graphics/gexiv2 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libhandy-1.so:x11-toolkits/libhandy \
		libpng.so:graphics/png \
		libportal.so:deskutils/libportal \
		libportal-gtk3.so:deskutils/libportal-gtk3 \
		librest-0.7.so:devel/librest \
		libtinysparql-3.0.so:devel/tinysparql
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome jpeg localbase meson pkgconfig \
		tar:xz
USE_GNOME=	cairo gdkpixbuf gtk30 libxml2
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.photos.gschema.xml
MESON_ARGS=	--buildtype \
		plain

.include <bsd.port.mk>
