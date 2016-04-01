# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbus-glib
PORTVERSION=	0.104
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-glib/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib bindings for the D-BUS messaging system

LIB_DEPENDS=	libdbus-1.so:devel/dbus

GNU_CONFIGURE=	yes
USES=		cpe gettext gmake libtool pathfix pkgconfig
CPE_VENDOR=	freedesktop
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-test-socket-dir=${WRKDIR} \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="1.0"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
