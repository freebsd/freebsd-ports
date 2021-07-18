# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	tiledb
PORTVERSION=	0.8.11
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the TileDB array storage manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=0.27:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.6.2:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.5.4:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16,1:math/py-numpy@${PY_FLAVOR} \
		tiledb>=2.2.8:databases/tiledb
LIB_DEPENDS=	libtiledb.so:databases/tiledb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16,1:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++14-lang localbase python:3.7+
USE_PYTHON=	autoplist concurrent cython distutils

.include <bsd.port.mk>
