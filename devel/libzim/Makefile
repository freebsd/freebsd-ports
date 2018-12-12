# $FreeBSD$

PORTNAME=	libzim
PORTVERSION=	4.0.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Reference implementation of the ZIM specification

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libxapian.so:databases/xapian-core

USES=		compiler:c++11-lang meson pkgconfig python:3.4+
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	openzim

BINARY_ALIAS=	python3=python${PYTHON_VER} python3-config=python${PYTHON_VER}-config
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
