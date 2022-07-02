# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
#   $MCom: ports/trunk/deskutils/gnome-system-log/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	gnome-system-log
PORTVERSION=	3.9.90
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 system log viewer

DEPRECATED=	Did not survive gnome 3
EXPIRATION_DATE= 2022-08-01

BUILD_DEPENDS=	itstool:textproc/itstool

CONFLICTS=	gnome-utils-2.[0-9]*

USES=		gettext gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack gtk30
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-system-log.gschema.xml

.include <bsd.port.mk>
