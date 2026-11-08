PORTNAME=	line-profiler
DISTVERSION=	5.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Line-by-line profiler for Python
WWW=		https://github.com/pyutils/line_profiler

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=7.10.7:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=7.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ubelt>=1.3.4:devel/py-ubelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdoctest>=1.1.3:devel/py-xdoctest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython pep517 pytest

# The PyPI distfile does not ship the tests/cython_example sources.
PYTEST_BROKEN_TESTS=	test_recover_cython_source test_profile_cython_source

TEST_ENV=	${MAKE_ENV} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH} \
		PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		TMPDIR=${WRKDIR}

do-test:
	@(cd ${WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${PYTHON_CMD} setup.py build_ext --inplace)
	@(cd ${WRKSRC}; ${SETENVI} ${WRK_ENV} ${TEST_ENV} \
		${PYTHON_CMD} -m pytest -k '${_PYTEST_FILTER_EXPRESSION}' \
		-rs -v -o addopts= ${TEST_ARGS:NDESTDIR=*})

post-patch:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/line_profiler/_line_profiler${PYTHON_TAG}.so

# tests as of 5.1.0: 306 passed, 2 skipped, 2 deselected, 1 xfailed in 89.37s

.include <bsd.port.mk>
