PORTNAME=	tiledb
PORTVERSION=	0.34.1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the TileDB array storage manager
WWW=		https://tiledb-inc-tiledb.readthedocs-hosted.com/projects/tiledb-py/en/stable/ \
		https://github.com/TileDB-Inc/TileDB-Py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: static assertion failed due to requirement 'sizeof(unsigned long long) <= sizeof(int)': Implicit narrowing is not permitted.

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.25,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=0<3:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		tiledb>=2.28.1:databases/tiledb
LIB_DEPENDS=	libtiledb.so:databases/tiledb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.25,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++17-lang localbase python:3.9+
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	TILEDB_PATH=${LOCALBASE}

post-patch:
	@${RM} -r ${WRKSRC}/ci/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
