# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/libgdata/Makefile,v 1.14 2010/09/30 19:39:17 kwm Exp $

PORTNAME=	libgdata
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implementation of the GData protocol

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gettext pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack intltool ltverhack glib20
CPPFLAGS+=	-I${LOCALBASE}/include 
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-html-dir="${PREFIX}/share/doc"

.include <bsd.port.mk>
