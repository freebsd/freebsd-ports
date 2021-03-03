# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygeos
PORTVERSION=	0.9
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GEOS wrapped in numpy ufuncs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	geos>=3.5:graphics/geos \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.13,1:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libgeos.so:graphics/geos
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.13,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent cython distutils

.include <bsd.port.mk>
