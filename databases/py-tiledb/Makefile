PORTNAME=	tiledb
PORTVERSION=	0.24.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the TileDB array storage manager
WWW=		https://github.com/TileDB-Inc/TileDB-Py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=0<3.0:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.23.2,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11210>=0<2.11.0:devel/py-pybind11210@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.5.4:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		tiledb>=2.18.2:databases/tiledb
LIB_DEPENDS=	libtiledb.so:databases/tiledb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.23.2,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR}

USES=		compiler:c++17-lang localbase python
USE_PYTHON=	autoplist concurrent cython pep517

MAKE_ENV=	TILEDB_PATH=${LOCALBASE}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
