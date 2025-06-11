PORTNAME=	aisleriot
DISTVERSION=	3.22.35
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of patience games written in guile scheme
WWW=		https://wiki.gnome.org/Apps/Aisleriot

LICENSE_COMB=	multi
LICENSE=	GPLv3+ LGPL3+ GFDL

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

CONFLICTS_INSTALL=	sol

USES=		gettext meson gnome guile:3.0 pkgconfig python:build \
		shebangfix tar:xz xorg
USE_GNOME=	cairo gtk30 librsvg2 libxml2:build
USE_XORG=	x11

MESON_ARGS=	-Dtheme_kde=false -Dguile=${GUILE_VER} \
		-Ddocs=false
SHEBANG_FILES=	data/icons/meson_updateiconcache.py \
		data/meson_desktopfile.py \
		src/lib/meson_compileschemas.py \
		src/meson_gconf.py

GLIB_SCHEMAS=	org.gnome.Patience.WindowState.gschema.xml

.include <bsd.port.mk>
