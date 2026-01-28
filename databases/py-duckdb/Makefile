PORTNAME=	duckdb
DISTVERSION=	1.4.4
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system
WWW=		https://duckdb.org/

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake-core \
		ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.6.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec>0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-storage>0:www/py-google-cloud-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
#TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyarrow>0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polars>0:misc/py-polars@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

MAKE_ENV=	OVERRIDE_GIT_DESCRIBE=v${DISTVERSION}-g00000000 \
		CMAKE_EXECUTABLE=${LOCALBASE}/bin/cmake \
		NINJA_EXECUTABLE=${LOCALBASE}/bin/ninja
TEST_WRKSRC=	${WRKDIR} # tests fail when run from the build directory due to a name collision with duckdb directory
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} # 2 tests fail, see https://github.com/duckdb/duckdb/issues/5642

.include <bsd.port.mk>
