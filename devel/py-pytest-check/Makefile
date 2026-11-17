PORTNAME=	pytest-check
DISTVERSION=	3.0.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pytest plugin allowing multiple failures per test
WWW=		https://github.com/okken/pytest-check

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7.0.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12.2:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 \
		PYTEST_PLUGINS=pytest_check.plugin
# this test fails when pytest-run-parallel is installed (it is not skipped) but its plugin is not loaded due to disabled autoload
TEST_ARGS=	--deselect tests/test_parallel_threads.py::test_check_failures_leak_across_parallel_threads

# tests as of 3.0.3: 119 passed, 3 skipped, 1 deselected in 1.48s

.include <bsd.port.mk>
