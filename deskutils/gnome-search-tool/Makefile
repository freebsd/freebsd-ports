# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-search-tool/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	gnome-search-tool
PORTVERSION=	3.6.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 file search utilities

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

CONFLICTS=	gnome-utils-2.[0-9]*

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gtk30 intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-search-tool.gschema.xml

.include <bsd.port.mk>
