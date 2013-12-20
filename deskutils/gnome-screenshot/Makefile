# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-screenshot/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	gnome-screenshot
PORTVERSION=	3.6.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 utility for making picutures of your screen

LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3

CONFLICTS=	gnome-utils-2.[0-9]*

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack gtk30
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-screenshot.gschema.xml

.include <bsd.port.mk>
