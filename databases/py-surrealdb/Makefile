PORTNAME=	surrealdb
PORTVERSION=	3.0.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SurrealDB python client
WWW=		https://github.com/surrealdb/surrealdb.py \
		https://surrealdb.com/docs/sdk/python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.14.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-core>=2.10.0:devel/py-pydantic-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=15.0:devel/py-websockets@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin \
		--ignore=tests/unit_tests/conformance \
		--ignore=tests/unit_tests/connections/embedded \
		--ignore=tests/unit_tests/test_examples_use_the_real_api.py

# tests as of 3.0.0: 1381 passed, 1165 skipped, 2 warnings in 21.54s

.include <bsd.port.mk>
