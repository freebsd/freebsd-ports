# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/libchamplain/Makefile,v 1.23 2010/09/27 18:17:23 kwm Exp $

PORTNAME=	libchamplain
PORTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A C library provides a Gtk+ widget to display rasterized maps/markers

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	clutter-gtk-0.10:${PORTSDIR}/graphics/clutter-gtk \
		soup-gnome-2.4:${PORTSDIR}/devel/libsoup-gnome
RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_BZIP2=	yes
USES=		pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk20 ltverhack:1
USE_SQLITE=	3
USE_AUTOTOOLS=	libtool
USE_GL=		gl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=0.8

NO_STAGE=	yes
.include <bsd.port.mk>
