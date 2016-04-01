# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgdata
PORTVERSION=	0.17.4
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

BUILD_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		gtkdoc-check:textproc/gtk-doc \
		vapigen:lang/vala
LIB_DEPENDS=	libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libgoa-1.0.so:net/gnome-online-accounts \
		libuhttpmock-0.0.so:net/uhttpmock \
		libgcr-3.so:security/gcr \
		liboauth.so:net/liboauth
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix intlhack \
		introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=--with-ca-certs=${LOCALBASE}/share/certs/ca-root-nss.crt

.include <bsd.port.mk>
