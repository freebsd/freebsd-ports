# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiledb
PORTVERSION=	0.8.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the TileDB array storage manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.5.4:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30:devel/py-wheel@${PY_FLAVOR} \
		${RUN_DEPENDS} \
		tiledb>=2.1.6:databases/tiledb
LIB_DEPENDS=	libtiledb.so:databases/tiledb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16,1:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++11-lang localbase python:3.5+
USE_PYTHON=	autoplist concurrent cython distutils

.include <bsd.port.mk>
