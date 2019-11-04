# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-maps
PORTVERSION=	3.28.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Map application for GNOME 3

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	geoclue>=0:net/geoclue
LIB_DEPENDS=	libgeocode-glib.so:net/geocode-glib \
		libgee-0.8.so:devel/libgee \
		libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libchamplain-0.12.so:graphics/libchamplain \
		libsoup-2.4.so:devel/libsoup \
		librest-0.7.so:devel/librest \
		libjson-glib-1.0.so:devel/json-glib \
		libfolks.so:net-im/folks \
		libgfbgraph-0.2.so:net/gfbgraph \
		libgjs.so:lang/gjs \
		libsoup-2.4.so:devel/libsoup \
		librest-0.7.so:devel/librest
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gl gmake gnome libtool \
		localbase pathfix pkgconfig tar:xz xorg
USE_GNOME=	cairo gtk30 intltool libxml2
USE_GL=		egl
USE_LDCONFIG=	yes
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Maps.gschema.xml

.include <bsd.port.mk>
