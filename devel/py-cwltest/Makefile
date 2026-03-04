PORTNAME=	cwltest
DISTVERSION=	2.6.20251216093331
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common Workflow Language testing framework
WWW=		https://github.com/common-workflow-language/cwltest

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}schema-salad>=8.7:devel/py-schema-salad@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}junit-xml>=1.9:textproc/py-junit-xml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 autoplist concurrent pytest

SHEBANG_FILES=	${WRKSRC}/tests/test-data/mock_cwl_runner.py

NO_ARCH=	yes

TEST_ENV=	PATH="${WRKDIR}/.local/bin:${PATH}"
# cwltool is not available as a port yet, so skip tests that require it
TEST_ARGS=	-p pytester tests/test_*.py -k "not test_plugin"
TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH}

# tests as of 2.6.20251216093331:
# Results (10.82s):
#        126 passed
#          9 deselected

.include <bsd.port.mk>
