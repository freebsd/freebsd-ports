# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/lang/gjs/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	gjs
PORTVERSION=	1.40.1
PORTREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libmozjs-24.so:${PORTSDIR}/lang/spidermonkey24

USES=		gettext gmake libtool pathfix pkgconfig \
		python:build tar:xz
USE_GNOME=	cairo glib20 gnomeprefix introspection:build \
		intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
