PORTNAME=	gnome-maps
DISTVERSION=	47.9
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Map application for GNOME
WWW=		https://apps.gnome.org/Maps/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	geoclue>=0:net/geoclue
LIB_DEPENDS=	libgeocode-glib-2.so:net/geocode-glib2 \
		libgjs.so:lang/gjs \
		libgweather-4.so:net/libgweather4 \
		librest-1.0.so:net/librest1 \
		libshumate-1.0.so:x11-toolkits/libshumate \
		libsoup-3.0.so:devel/libsoup3 \
		libportal.so:deskutils/libportal \
		libportal-gtk4.so:deskutils/libportal-gtk4 \
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	geoclue>=0:net/geoclue

USES=		desktop-file-utils gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo glib20 gtk40 introspection:build libadwaita \
		libxml2 librsvg2
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.Maps.gschema.xml

.include <bsd.port.mk>
