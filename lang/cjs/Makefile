# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cjs
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	lang gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JavaScript bindings based on gobject-introspection

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libmozjs-24.so:lang/spidermonkey24

CONFLICTS_BUILD=spidermonkey17-1.7.*

USES=		autoreconf compiler:c11 gettext libtool gmake \
		pathfix pkgconfig python:build shebangfix
USE_GNOME=	cairo glib20 gnomeprefix introspection:build
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--enable-compile-warnings=no


.include <bsd.port.mk>
