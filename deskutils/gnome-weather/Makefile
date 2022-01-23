# Created by: Gustau Perez <gustau.perez@gmail.com>

PORTNAME=	gnome-weather
PORTVERSION=	41.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	4be71525f071.patch:-p1 # https://gitlab.gnome.org/GNOME/gnome-weather/-/merge_requests/92

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Weather application for GNOME 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.md

LIB_DEPENDS=	libgweather-3.so:net/libgweather \
		libgeoclue-2.so:net/geoclue \
		libgjs.so:lang/gjs \
		libhandy-1.so:x11-toolkits/libhandy

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig tar:xz
USE_GNOME=	gtk30
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.Weather.gschema.xml

.include <bsd.port.mk>
