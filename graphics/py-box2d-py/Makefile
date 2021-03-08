# $FreeBSD$

PORTNAME=	box2d-py
DISTVERSION=	2.3.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	2D physics library Box2D 2.3 for usage in Python

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libbox2d.so:misc/box2d

USES=		compiler:c11 python:3.6+
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Box2D/_Box2D.so

.include <bsd.port.mk>
