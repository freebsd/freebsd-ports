PORTNAME=	gnome-weather
PORTVERSION=	47.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Weather application for GNOME
WWW=		https://apps.gnome.org/Weather/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.md

PORTSCOUT=	limit:^47\.

LIB_DEPENDS=	libgeoclue-2.so:net/geoclue \
		libgjs.so:lang/gjs \
		libgweather-4.so:net/libgweather4

USES=		desktop-file-utils gettext gnome localbase meson pkgconfig \
		tar:xz
USE_GNOME=	glib20 gtk40 introspection:build libadwaita
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.Weather.gschema.xml

.include <bsd.port.mk>
