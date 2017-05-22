# $FreeBSD$

PORTNAME=	libsearpc
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Simple RPC framework based on GObject System in C

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libgobject-2.0.so:devel/glib20

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_TAGNAME=	v3.1-latest

USES=		autoreconf gettext libtool pathfix pkgconfig python:2
USE_LDCONFIG=	yes
BROKEN=		checksum mismatch

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
