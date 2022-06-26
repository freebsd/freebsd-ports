PORTNAME=	duckdb
DISTVERSION=	0.4.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.6.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-storage>0:www/py-google-cloud-storage@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail, see https://github.com/duckdb/duckdb/issues/3924

TEST_WRKSRC=	${WRKDIR} # tests fail when run from the build directory due to a name collision with duckdb directory
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# 2 tests are known to fail, see https://github.com/duckdb/duckdb/issues/3930

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/duckdb.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
