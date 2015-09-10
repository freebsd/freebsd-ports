# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/clutter-gtk3/Makefile 19945 2014-10-15 05:41:04Z gusi $

PORTNAME=	clutter-gtk
PORTVERSION=	1.6.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

LIB_DEPENDS=	libclutter-1.0.so:${PORTSDIR}/graphics/clutter

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gtk30 introspection
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
