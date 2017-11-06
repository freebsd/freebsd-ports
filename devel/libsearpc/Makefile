# $FreeBSD$

PORTNAME=	libsearpc
PORTVERSION=	3.0.8
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Simple RPC framework based on GObject System in C

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libgobject-2.0.so:devel/glib20

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_TAGNAME=	12a0126

USES=		autoreconf gettext libtool pathfix pkgconfig python:2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
