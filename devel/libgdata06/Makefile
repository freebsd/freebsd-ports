# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgdata06/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	libgdata
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	06

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

CONFLICTS=	libgdata-0.10.*

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	intltool ltverhack glib20 introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-html-dir="${PREFIX}/share/doc"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdata.so.7

.include <bsd.port.mk>
