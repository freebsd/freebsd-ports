PORTNAME=	hishel
PORTVERSION=	1.1.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Elegant HTTP Caching for Python
WWW=		https://hishel.com/ \
		https://github.com/karpetrosyan/hishel

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.1.2:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14.1:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ASYNC FASTAPI HTTPX REQUESTS
ASYNC_DESC=	Asynchronous support
FASTAPI_DESC=	FastAPI support
HTTPX_DESC=	HTTPX support
HTTPX_IMPLIES=	ASYNC
REQUESTS_DESC=	Requests support

ASYNC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.9.0:devel/py-anyio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}anysqlite>=0.0.5:databases/py-anysqlite@${PY_FLAVOR}
FASTAPI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastapi>=0.119.1:www/py-fastapi@${PY_FLAVOR}
HTTPX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.28.0:www/py-httpx@${PY_FLAVOR}
REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
