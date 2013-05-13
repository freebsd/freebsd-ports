# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	dbus-glib
PORTVERSION=	0.100.2
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-glib/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib bindings for the D-BUS messaging system

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus

USE_GNOME=	gnomehack glib20 ltverhack
USES=		gettext
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-test-socket-dir=${WRKDIR} \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="1.0"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

MAN1=		dbus-binding-tool.1

.include <bsd.port.mk>
