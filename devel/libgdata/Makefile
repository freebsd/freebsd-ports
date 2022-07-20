PORTNAME=	libgdata
PORTVERSION=	0.17.13
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib-based implementation of the GData protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	uhttpmock>0:net/uhttpmock \
		valac:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libp11-kit.so:security/p11-kit \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgcr-base-3.so:security/gcr \
		liboauth.so:net/liboauth

USES=		gettext gnome localbase meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
