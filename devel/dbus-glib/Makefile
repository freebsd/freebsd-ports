# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	dbus-glib
PORTVERSION=	0.100.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-glib/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib bindings for the D-BUS messaging system

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-test-socket-dir=${WRKDIR} \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="1.0"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
