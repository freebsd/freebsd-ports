# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	file-roller
PORTVERSION=	3.28.0
PORTEPOCH=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Archive manager for zip files, tar, etc

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libnotify.so:devel/libnotify
RUN_DEPENDS=	gtar:archivers/gtar

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext libarchive localbase \
		meson pkgconfig python:3.5+,build tar:xz
USE_GNOME=	cairo gtk30
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
MESON_ARGS=	-Dpackagekit=false
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.FileRoller.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NAUTILUS
OPTIONS_DEFAULT=NAUTILUS

NAUTILUS_DESC=	Nautilus context menu actions
NAUTILUS_USE=	GNOME=nautilus3
NAUTILUS_MESON_TRUE=	nautilus-actions

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

.include <bsd.port.mk>
