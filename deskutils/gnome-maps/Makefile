PORTNAME=	gnome-maps
DISTVERSION=	43.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Map application for GNOME
WWW=		https://wiki.gnome.org/Apps/Maps

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	geoclue>=0:net/geoclue
LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libgee-0.8.so:devel/libgee \
		libgeocode-glib-2.so:net/geocode-glib2 \
		libgfbgraph-0.2.so:net/gfbgraph \
		libgjs.so:lang/gjs \
		libgweather-4.so:net/libgweather4 \
		libhandy-1.so:x11-toolkits/libhandy \
		libjson-glib-1.0.so:devel/json-glib \
		librest-1.0.so:net/librest1 \
		libshumate-1.0.so:x11-toolkits/libshumate \
		libsoup-3.0.so:devel/libsoup3
RUN_DEPENDS=	geoclue>=0:net/geoclue

USES=		desktop-file-utils gettext gl gnome meson pkgconfig tar:xz xorg
USE_GNOME=	cairo gtk40 intltool libadwaita libxml2
USE_GL=		egl
USE_LDCONFIG=	yes
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Maps.gschema.xml

.include <bsd.port.mk>
