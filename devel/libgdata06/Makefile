# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgdata06/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libgdata
PORTVERSION=	0.6.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	06

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

CONFLICTS=	libgdata-0.10.*

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	intltool glib20 introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--with-html-dir="${PREFIX}/share/doc"

.include <bsd.port.mk>
