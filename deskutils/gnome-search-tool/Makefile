# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
#   $MCom: ports/trunk/deskutils/gnome-search-tool/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	gnome-search-tool
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 file search utilities

DEPRECATED=	Did not survive gnome3
EXPIRATION_DATE=	2022-08-01

BUILD_DEPENDS=	itstool:textproc/itstool

CONFLICTS=	gnome-utils-2.[0-9]*

USES=		gettext gmake gnome pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix gtk30 intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-search-tool.gschema.xml

.include <bsd.port.mk>
