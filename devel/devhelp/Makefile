# Created by: Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=	devhelp
PORTVERSION=	41.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	f1c27fd4eaa5.patch:-p1 # https://gitlab.gnome.org/GNOME/devhelp/-/merge_requests/42

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libamtk-5.so:x11-toolkits/amtk

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gnome localbase meson pkgconfig \
		python:3.3+,build tar:xz
USE_GNOME=	cairo gtk30 introspection

USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.devhelp.gschema.xml \
		org.gnome.libdevhelp-3.gschema.xml

.include <bsd.port.mk>
