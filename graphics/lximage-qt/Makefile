# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lximage-qt
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Image viewer and screenshot tool

LICENSE=	GPLv2

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libmenu-cache.so:x11/menu-cache

USES=	cmake compiler:c++14-lang desktop-file-utils gettext-runtime \
	gnome localbase:ldflags lxqt pkgconfig qt:5 gnome tar:xz xorg

USE_GNOME=	glib20
USE_QT=		buildtools_build qmake_build core dbus gui linguisttools \
		network printsupport svg widgets x11extras
USE_LXQT=	buildtools libfmqt
USE_XORG=	ice sm x11 xcb xext xfixes

.include <bsd.port.mk>
