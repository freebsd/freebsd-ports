PORTNAME=	jsonrpc-glib
PORTVERSION=	3.42.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to communicate using the JSON-RPC 2.0 specification

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib

USES=		compiler:c11 gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 introspection:build

.include <bsd.port.mk>
