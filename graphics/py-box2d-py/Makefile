# $FreeBSD$

PORTNAME=	box2d-py
DISTVERSION=	2.3.8
CATEGORIES=	graphics
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	neel@neelc.org
COMMENT=	2D physics library Box2D 2.3 for usage in Python

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libBox2D.so:misc/box2d

USES=		compiler:c11 python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
