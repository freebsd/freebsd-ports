PORTNAME=	gnome-characters
PORTVERSION=	47.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Find and insert unusual characters for GNOME
WWW=		https://apps.gnome.org/Characters/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

BUILD_DEPENDS=	update-desktop-database:devel/desktop-file-utils
LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita \
		libdbus-1.so:devel/dbus \
		libgjs.so:lang/gjs \

USES=		gettext gnome iconv:wchar_t localbase:ldflags meson pkgconfig \
		python:build tar:xz
USE_GNOME=	gtk40 introspection pango gnomedesktop3
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Characters.gschema.xml

.include <bsd.port.mk>
