# $FreeBSD$

PORTNAME=	libsearpc
PORTVERSION=	3.0.0
CATEGORIES=	devel

MAINTAINER=	yan_jingfeng@yahoo.com
COMMENT=	Simple RPC framework based on GObject System in C

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjansson.so:${PORTSDIR}/devel/jansson \
		libgobject-2.0.so:${PORTSDIR}/devel/glib20

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_TAGNAME=	v3.0-latest
GH_COMMIT=	8998e7b

USES=		autoreconf libtool pathfix pkgconfig python:2
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
