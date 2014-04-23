# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/libgdata/Makefile,v 1.14 2010/09/30 19:39:17 kwm Exp $

PORTNAME=	libgdata
PORTVERSION=	0.6.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implementation of the GData protocol

LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gettext gmake libtool:keepla pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 intltool introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include 
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--with-html-dir="${PREFIX}/share/doc"

.include <bsd.port.mk>
