PORTNAME=	gnome-2048
PORTVERSION=	3.38.2
PORTREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	194e22699f71.patch:-p1 # https://gitlab.gnome.org/GNOME/gnome-2048/-/merge_requests/21

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Move the tiles until you obtain the 2048 tile
WWW=		https://wiki.gnome.org/Apps/2048

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstream-util:devel/appstream-glib
LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libcogl.so:graphics/cogl \
		libgee-0.8.so:devel/libgee \
		libgnome-games-support-1.so:games/libgnome-games-support \
		libjson-glib-1.0.so:devel/json-glib

PORTSCOUT=	limitw:1,even

USES=		gettext gl gmake gnome localbase meson pathfix pkgconfig tar:xz vala:build xorg
USE_GNOME=	cairo gtk30 intltool libxml2:build
USE_GL=		egl
USE_XORG+=	x11 xext xdamage xfixes xcomposite xi xrandr

GLIB_SCHEMAS=	org.gnome.TwentyFortyEight.gschema.xml

.include <bsd.port.mk>
