# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	mlview
PORTVERSION=	0.8
PORTREVISION=	14
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tree oriented XML editor for Gnome

USE_AUTOTOOLS=	autoconf libtool
USES=		pathfix gmake iconv pkgconfig tar:bzip2
USE_GNOME=	eel2 gnomeprefix gtksourceview libgnomeui
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib `pkg-config --libs gnome-vfs-2.0 libgnomeui-2.0` ${ICONV_LIB}"
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags gnome-vfs-2.0 libgnomeui-2.0`

GCONF_SCHEMAS=	mlview.schemas

OPTIONS_DEFINE=	DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_ENABLE=	dbus

.include <bsd.port.mk>
