# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/clutter-gtk3/Makefile 18798 2013-10-14 10:04:09Z gusi $

PORTNAME=	clutter-gtk
PORTVERSION=	1.4.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

LIB_DEPENDS=	libclutter-1.0.so:${PORTSDIR}/graphics/clutter

LATEST_LINK=	clutter-gtk3
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gtk30 ltverhack
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
