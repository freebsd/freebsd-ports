# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	lightsoff
PORTVERSION=	3.28.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome ligthsoff

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib

PORTSCOUT=	limitw:1,even

USES=		gettext gl gmake gnome localbase pathfix pkgconfig \
		sqlite tar:xz xorg
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build
INSTALLS_ICONS=	yes
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
USE_GL=		egl gl
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.lightsoff.gschema.xml

.include <bsd.port.mk>
