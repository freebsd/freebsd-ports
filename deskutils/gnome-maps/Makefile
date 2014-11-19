# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-maps/Makefile 19980 2014-10-17 06:01:57Z gusi $

PORTNAME=	gnome-maps
PORTVERSION=	3.14.1.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Map application for GNOME 3

BUILD_DEPENDS=	geoclue>=0:${PORTSDIR}/net/geoclue \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libgeocode-glib.so:${PORTSDIR}/net/geocode-glib \
		libgjs.so:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	geoclue>=0:${PORTSDIR}/net/geoclue

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.maps.gschema.xml

.include <bsd.port.mk>
