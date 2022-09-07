PORTNAME=	at-spi2-atk
PORTVERSION=	2.38.0
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Assisted Technology Provider module for GTK+
WWW=		https://gitlab.gnome.org/GNOME/at-spi2-atk

LICENSE=	LGPL21

BUILD_DEPENDS=	at-spi2-core>=2.17.90:accessibility/at-spi2-core
LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	at-spi2-core>=2.17.90:accessibility/at-spi2-core

PORTSCOUT=	limitw:1,even

USES=		cpe gettext-runtime gnome localbase meson pkgconfig tar:xz
USE_GNOME=	atk glib20 intlhack
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome

.include <bsd.port.mk>
