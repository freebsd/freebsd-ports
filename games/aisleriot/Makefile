PORTNAME=	aisleriot
DISTVERSION=	3.22.25
PORTREVISION=	3
CATEGORIES=	games gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of patience games written in guile scheme
WWW=		https://wiki.gnome.org/Apps/Aisleriot

LICENSE=	GPLv3

BUILD_DEPENDS=	itstool:textproc/itstool \
		bash:shells/bash
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

CONFLICTS_INSTALL=	sol
PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext meson gnome guile:2.2,3.0 \
		pkgconfig python:build shebangfix xorg
USE_GITLAB=	yes
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build
USE_XORG=	x11

GL_SITE=	https://gitlab.gnome.org/
GL_ACCOUNT=	GNOME
GL_TAGNAME=	8a4542d2f44ee1425a56ac7595ed51449ae0290e

MESON_ARGS=	-Dtheme_kde=false -Dguile=${GUILE_VER}
SHEBANG_FILES=	data/icons/meson_updateiconcache.py \
		data/meson_desktopfile.py \
		src/lib/meson_compileschemas.py \
		src/meson_gconf.py

GLIB_SCHEMAS=	org.gnome.Patience.WindowState.gschema.xml

.include <bsd.port.mk>
