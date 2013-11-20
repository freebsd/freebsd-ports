# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/devel/libgdata/Makefile 18878 2013-11-11 19:28:42Z gusi $

PORTNAME=	libgdata
PORTVERSION=	0.14.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

BUILD_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		liboauth.so:${PORTSDIR}/net/liboauth
RUN_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	libgdata-0.6.*

USE_XZ=		yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomeprefix intltool introspection:build ltverhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-ca-certs=${LOCALBASE}/share/certs/ca-root-nss.crt

post-install:
	 @${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdata.so.13

.include <bsd.port.mk>
