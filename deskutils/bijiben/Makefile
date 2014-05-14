# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/bijiben/Makefile 19641 2014-05-13 06:13:20Z gusi $

PORTNAME=	bijiben
PORTVERSION=	3.12.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Note editor designed to remain simple to use

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack \
		introspection:build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
