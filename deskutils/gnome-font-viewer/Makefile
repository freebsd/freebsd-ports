# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-font-viewer/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	gnome-font-viewer
PORTVERSION=	3.6.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 font viewer utility

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

CONFLICTS=	gnome-utils-2.[0-9]*

USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gtk30 gnomedesktop3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
