# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-characters
PORTVERSION=	3.34.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Find and insert unusual characters for GNOME

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

LIB_DEPENDS=	libgjs.so:lang/gjs \
		libunistring.so:devel/libunistring \
		libdbus-1.so:devel/dbus

USES=		gettext gnome iconv:wchar_t localbase:ldflags meson \
		pkgconfig python:3.6+,build tar:xz
USE_GNOME=	gtk30 introspection
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Characters.gschema.xml

.include <bsd.port.mk>
