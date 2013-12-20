# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-system-log/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	gnome-system-log
PORTVERSION=	3.6.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 system log viewer

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

CONFLICTS=	gnome-utils-2.[0-9]*

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gtk30
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-system-log.gschema.xml

.include <bsd.port.mk>
