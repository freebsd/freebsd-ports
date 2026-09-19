PORTNAME=	param
DISTVERSION=	2.4.2
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Module to make Python code clearer and more reliable
WWW=		https://param.holoviz.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} LD_LIBRARY_PATH=/lib:/usr/lib
TEST_ARGS=	--disable-plugin-autoload \
		-o filterwarnings=default \
		-p pytest_asyncio.plugin -p pytest_cov
PYTEST_IGNORED_TESTS=	test_no_blocklist_imports test_parameterized_warns_explicit_no_ref \
			test_reactive_gen_pipe_with_dep test_reactive_gen_with_dep \
			test_reactive_lazy_gen_pipe

# tests as of 2.4.2: 1546 passed, 6 skipped, 5 deselected, 2 xfailed in 33.81s
# test_no_blocklist_imports is ignored because upstream now imports the stdlib
# html module in param/parameterized.py for _repr_html_ support.
# test_parameterized_warns_explicit_no_ref is ignored because it is a known
# upstream failure/flaky test, see https://github.com/holoviz/param/issues/952
# test_reactive_gen_pipe_with_dep, test_reactive_gen_with_dep, and
# test_reactive_lazy_gen_pipe are ignored because they are flaky on FreeBSD
# arm64.

.include <bsd.port.mk>
