PORTNAME=	gnote
PORTVERSION=	47.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ version of Tomboy, note taking application
WWW=		https://gitlab.gnome.org/GNOME/gnote

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libuuid.so:misc/libuuid

PORTSCOUT=	limit:^47\.

USES=		compiler:c++17-lang desktop-file-utils gettext gnome localbase \
		meson pkgconfig python:build tar:xz
USE_GNOME=	glib20 gtkmm40 libadwaita libxml2 libxslt
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.gnote.gschema.xml

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
