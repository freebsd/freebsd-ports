# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	gnome-2048
PORTVERSION=	3.22.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Move the tiles until you obtain the 2048 tile

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool \
		appstream-util:devel/appstream-glib
LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libcogl.so:graphics/cogl \
		libgee-0.8.so:devel/libgee \
		libgnome-games-support-1.so:games/libgnome-games-support \
		libjson-glib-1.0.so:devel/json-glib

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intltool libxml2:build
USE_GL=		egl
USE_XORG+=	x11 xext xdamage xfixes xcomposite xi xrandr
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.2048.gschema.xml

.include <bsd.port.mk>
