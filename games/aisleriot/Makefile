# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	aisleriot
DISTVERSION=	3.22.19
CATEGORIES=	games gnome
MASTER_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/archive/${PORTVERSION}/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of patience games written in guile scheme

LICENSE=	GPLv3

BUILD_DEPENDS=	itstool:textproc/itstool \
		bash:shells/bash
LIB_DEPENDS=	libguile-2.2.so:lang/guile2 \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libgc-threaded.so:devel/boehm-gc-threaded

CONFLICTS_INSTALL=	sol
PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext meson gnome pkgconfig \
		python:build,3.6+ shebangfix xorg
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build
USE_XORG=	x11

MESON_ARGS=	-Dtheme_kde=false
SHEBANG_FILES=	data/icons/meson_updateiconcache.py \
		data/meson_desktopfile.py \
		src/lib/meson_compileschemas.py \
		src/meson_gconf.py

GLIB_SCHEMAS=	org.gnome.Patience.WindowState.gschema.xml

.include <bsd.port.mk>
