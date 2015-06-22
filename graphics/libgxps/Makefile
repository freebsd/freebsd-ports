# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/libgxps/Makefile 19811 2014-08-14 12:45:34Z gusi $

PORTNAME=	libgxps
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject based library for rendering XPS documents

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		liblcms2.so:${PORTSDIR}/graphics/lcms2

USES=		gettext gmake jpeg libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gnomeprefix glib20 intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -larchive
CONFIGURE_ARGS+=	--enable-introspection=no
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
