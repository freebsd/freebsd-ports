# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-weather/Makefile 19822 2014-08-20 08:57:46Z gusi $

PORTNAME=	gnome-weather
PORTVERSION=	3.12.1
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Weather application for GNOME 3

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgweather-3.so:${PORTSDIR}/net/libgweather \
		libgjs.so:${PORTSDIR}/lang/gjs

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
