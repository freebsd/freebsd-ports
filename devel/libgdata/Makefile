# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/devel/libgdata/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libgdata
PORTVERSION=	0.14.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

BUILD_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss \
		vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		liboauth.so:${PORTSDIR}/net/liboauth
RUN_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	libgdata-0.6.*

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomehier gnomeprefix intltool \
			introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--with-ca-certs=${LOCALBASE}/share/certs/ca-root-nss.crt

.include <bsd.port.mk>
