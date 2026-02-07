PORTNAME=	jsonrpc-glib
PORTVERSION=	3.44.2
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to communicate using the JSON-RPC 2.0 specification
WWW=		https://gitlab.gnome.org/GNOME/jsonrpc-glib

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib

USES=		compiler:c11 gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
