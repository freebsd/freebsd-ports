PORTNAME=	gnome-calendar
PORTVERSION=	42.2
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple and beautiful calendar application for GNOME
WWW=		https://wiki.gnome.org/Apps/Calendar/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libical.so:devel/libical \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libsoup-3.0.so:devel/libsoup3 \
		libgweather-4.so:net/libgweather4 \
		libgeoclue-2.so:net/geoclue \
		libgeocode-glib.so:net/geocode-glib \
		libgoa-1.0.so:net/gnome-online-accounts \
		libhandy-1.so:x11-toolkits/libhandy
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome \
		localbase:ldflags meson pkgconfig python:build tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo evolutiondataserver3 gtksourceview3 libadwaita
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.calendar.enums.xml \
		org.gnome.calendar.gschema.xml

.include <bsd.port.mk>
