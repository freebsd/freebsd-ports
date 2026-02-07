PORTNAME=	devhelp
PORTVERSION=	41.2
PORTREVISION=	6
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	f1c27fd4eaa5.patch:-p1 # https://gitlab.gnome.org/GNOME/devhelp/-/merge_requests/42

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME
WWW=		https://wiki.gnome.org/Apps/Devhelp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gnome localbase meson pkgconfig \
		python:build tar:xz
USE_GNOME=	cairo gtk30 introspection

USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.devhelp.gschema.xml \
		org.gnome.libdevhelp-3.gschema.xml

.include <bsd.port.mk>
