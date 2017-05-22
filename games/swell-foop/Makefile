# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	swell-foop
PORTVERSION=	3.24.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome swell-foop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack libxml2:build
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
INSTALLS_ICONS=	yes
USE_GL=		egl gl
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.swell-foop.gschema.xml

.include <bsd.port.mk>
