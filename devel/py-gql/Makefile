PORTNAME=	gql
PORTVERSION=	3.5.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	GraphQL client for Python
WWW=		https://github.com/graphql-python/gql

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.0<5:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backoff>=1.11.1<3.0:devel/py-backoff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core>=3.2<3.3:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.6<2.0:www/py-yarl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>0:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parse>0:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-console-scripts>0:devel/py-pytest-console-scripts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcrpy>0:devel/py-vcrpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		AIOHTTP BOTOCORE DOCS HTTPX REQUESTS WEBSOCKETS
OPTIONS_DEFAULT=	AIOHTTP BOTOCORE HTTPX REQUESTS WEBSOCKETS

AIOHTTP_DESC=		AIOHTTP Support
BOTOCORE_DESC=		BOTOCORE Support
HTTPX_DESC=		HTTPX Support
REQUESTS_DESC=		Requests Support
WEBSOCKETS_DESC=	Websockets Support

AIOHTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.0<4:www/py-aiohttp@${PY_FLAVOR}

BOTOCORE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.21<2:devel/py-botocore@${PY_FLAVOR}

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.0<5:devel/py-anyio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}backoff>=1.11.1<3.0:devel/py-backoff@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}graphql-core>=3.2<3.3:devel/py-graphql-core@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-argparse>0:textproc/py-sphinx-argparse@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=4.3.1,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

HTTPX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.23.1<1:www/py-httpx@${PY_FLAVOR}

REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=1.0.0<2:www/py-requests-toolbelt@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=2.26<3:www/py-requests@${PY_FLAVOR}

WEBSOCKETS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}websockets>=10:devel/py-websockets@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts= tests -vv --run-online

.include <bsd.port.mk>
