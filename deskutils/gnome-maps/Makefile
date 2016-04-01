# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-maps
PORTVERSION=	3.18.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Map application for GNOME 3

BUILD_DEPENDS=	geoclue>=0:net/geoclue \
		itstool:textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libgeocode-glib.so:net/geocode-glib \
		libgee-0.8.so:devel/libgee \
		libchamplain-0.12.so:graphics/libchamplain \
		libfolks.so:net-im/folks \
		libgjs.so:lang/gjs
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Maps.gschema.xml

.include <bsd.port.mk>
