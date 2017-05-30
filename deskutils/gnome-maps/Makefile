# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-maps
PORTVERSION=	3.24.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

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
		libgjs.so:lang/gjs
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libtool \
		localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intltool libxml2
USE_GL=		egl
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Maps.gschema.xml

.include <bsd.port.mk>
