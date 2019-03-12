# $FreeBSD$

PORTNAME=	jsonrpc-glib
PORTVERSION=	3.28.1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to communicate using the JSON-RPC 2.0 specification

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib

USES=		compiler:c11 gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

.include <bsd.port.mk>
