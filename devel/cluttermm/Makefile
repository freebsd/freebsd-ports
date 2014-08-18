# Created by: Gustau Pérez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/devel/cluttermm/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	cluttermm
PORTVERSION=	1.17.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for clutter

LIB_DEPENDS=	libclutter-1.0.so:${PORTSDIR}/graphics/clutter

USES+=		gettext gmake libtool pathfix perl5 pkgconfig tar:xz
USE_GNOME=	atkmm glib20 gtkmm30 libsigc++20 pangomm
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
