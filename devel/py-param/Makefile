PORTNAME=	param
DISTVERSION=	2.4.1
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
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ARGS=	-o filterwarnings=default -p no:benchmark -p no:cov -p no:black -p no:mypy
PYTEST_IGNORED_TESTS=	test_parameterized_warns_explicit_no_ref test_reactive_lazy_gen_pipe

# tests as of 2.4.1: 1515 passed, 1 skipped, 2 xfailed in 21.92s
# test_parameterized_warns_explicit_no_ref and test_reactive_lazy_gen_pipe are
# ignored because they are known upstream failures/flaky tests, see
# https://github.com/holoviz/param/issues/952

.include <bsd.port.mk>
