# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-clocks
PORTVERSION=	3.24.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clocks for GNOME 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		vala:lang/vala
LIB_DEPENDS=	libgeoclue-2.so:net/geoclue \
		libgeocode-glib.so:net/geocode-glib \
		libgweather-3.so:net/libgweather

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gnomedesktop3 gsound
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.clocks.gschema.xml

.include <bsd.port.mk>
