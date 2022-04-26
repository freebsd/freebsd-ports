PORTNAME=	asttokens
PORTVERSION=	2.0.5
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Annotate AST trees with source code positions

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>0:devel/py-astroid@${PY_FLAVOR}

USES=		python:3.6+ pytest
USE_PYTHON=	autoplist distutils
PYTEST_ARGS=	--ignore=tests/testdata
NO_ARCH=	yes

PYTEST_BROKEN_TESTS=	test_async_def test_decorators test_fixture10 \
			test_fixture11 test_fixture13 test_fixture3 \
			test_fixture4 test_fixture5 test_fixture7 \
			test_fixture8 test_fixture9 test_fstrings \
			test_mark_tokens_simple test_print_function \
			test_slices test_splat test_sys_modules \
			test_tuples test_assignment_expressions

.include <bsd.port.mk>
