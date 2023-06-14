PORTNAME=	gnome-clocks
PORTVERSION=	40.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clocks for GNOME
WWW=		https://wiki.gnome.org/Apps/Clocks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgeoclue-2.so:net/geoclue \
		libgeocode-glib.so:net/geocode-glib \
		libgweather-3.so:net/libgweather \
		libhandy-1.so:x11-toolkits/libhandy

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		python:build shebangfix tar:xz vala:build
USE_LDCONFIG=	yes
USE_GNOME=	cairo gnomedesktop3 gsound
SHEBANG_FILES=	build-aux/post-install.py

GLIB_SCHEMAS=	org.gnome.clocks.gschema.xml

.include <bsd.port.mk>
