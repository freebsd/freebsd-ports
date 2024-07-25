PORTNAME=	tiledb
PORTVERSION=	0.30.2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the TileDB array storage manager
WWW=		https://tiledb-inc-tiledb.readthedocs-hosted.com/projects/tiledb-py/en/stable/ \
		https://github.com/TileDB-Inc/TileDB-Py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.25,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=1.5.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30:devel/py-wheel@${PY_FLAVOR} \
		tiledb>=2.24.2:databases/tiledb
LIB_DEPENDS=	libtiledb.so:databases/tiledb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.25,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR}

USES=		compiler:c++17-lang localbase python
USE_PYTHON=	autoplist concurrent cython pep517

MAKE_ENV=	TILEDB_PATH=${LOCALBASE}

post-patch:
	@${RM} -r ${WRKSRC}/ci/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
