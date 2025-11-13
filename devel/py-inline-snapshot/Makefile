PORTNAME=	inline-snapshot
DISTVERSION=	0.31.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	inline_snapshot-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Create and update inline snapshots in your Python code
WWW=		https://github.com/15r10nk/inline-snapshot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asttokens>=2.0.5:devel/py-asttokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}executing>=2.2.0:devel/py-executing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=8.3.4:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PY_TOMLI}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=6.75.5:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=1.2.0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=1:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyright>=1.1.359:devel/py-pyright@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-freezer>=0.4.9:devel/py-pytest-freezer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subtests>=0.11.0:devel/py-pytest-subtests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1,1:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest
# These tests fails and require some more investigation
PYTEST_BROKEN_TESTS=	test_typing_args[pyright] test_typing_call[pyright]
# These tests require www/node
PYTEST_IGNORED_TESTS=	test_black_formatting_error test_no_black test_compare

NO_ARCH=	yes

OPTIONS_DEFINE=		BLACK DIRTY-EQUALS
OPTIONS_DEFAULT=	BLACK DIRTY-EQUALS

BLACK_DESC=		Format generated code with Black
DIRTY-EQUALS_DESC=	Support for normalization of data that changes frequently

BLACK_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}black>=23.3.0:devel/py-black@${PY_FLAVOR}
DIRTY-EQUALS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dirty-equals>=0.9.0:devel/py-dirty-equals@${PY_FLAVOR}

.include <bsd.port.mk>
