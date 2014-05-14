# Created by: Gustau Pérez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/devel/cluttermm/Makefile 19621 2014-05-12 08:35:22Z gusi $

PORTNAME=	cluttermm
PORTVERSION=	1.17.3
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for clutter

LIB_DEPENDS=	libclutter-1.0.so:${PORTSDIR}/graphics/clutter

USES+=		gettext gmake libtool:keepla pathfix perl5 pkgconfig tar:xz
USE_GNOME=	atkmm glib20 gtkmm30 libsigc++20 pangomm
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
