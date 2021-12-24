# Created by: Gustau Perez <gustau.perez@gmail.com>

PORTNAME=	gnome-maps
DISTVERSION=	41.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Map application for GNOME 3

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	geoclue>=0:net/geoclue
LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libfolks.so:net-im/folks \
		libgee-0.8.so:devel/libgee \
		libgeocode-glib.so:net/geocode-glib \
		libgfbgraph-0.2.so:net/gfbgraph \
		libgjs.so:lang/gjs \
		libhandy-1.so:x11-toolkits/libhandy \
		libjson-glib-1.0.so:devel/json-glib \
		librest-0.7.so:devel/librest \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gl gnome meson pkgconfig tar:xz xorg
USE_GNOME=	cairo gtk30 intltool libxml2
USE_GL=		egl
USE_LDCONFIG=	yes
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Maps.gschema.xml

.include <bsd.port.mk>
