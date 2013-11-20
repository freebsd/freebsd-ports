# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgdata06/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgdata
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

CONFLICTS=	libgdata-0.10.*

NO_STAGE=	yes
LATEST_LINK=	libgdata06
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	intltool ltverhack glib20 introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-html-dir="${PREFIX}/share/doc"

.include <bsd.port.mk>
