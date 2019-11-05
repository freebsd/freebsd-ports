# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter-gtk
PORTVERSION=	1.8.4
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext gl gnome localbase meson pkgconfig tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
USE_GL=		egl
USE_LDCONFIG=	yes

.include <bsd.port.mk>
