# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/libchamplain/Makefile,v 1.23 2010/09/27 18:17:23 kwm Exp $

PORTNAME=	libchamplain
PORTVERSION=	0.8.1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C library provides a Gtk+ widget to display rasterized maps/markers

LIB_DEPENDS=	libclutter-gtk-0.10.so:${PORTSDIR}/graphics/clutter-gtk \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

USES=		gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix gtk20 introspection:build,run
USE_SQLITE=	3
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgthread-2.0
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=0.8

.include <bsd.port.mk>
