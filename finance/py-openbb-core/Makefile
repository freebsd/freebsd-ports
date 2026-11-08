PORTNAME=	openbb-core
DISTVERSION=	2.0.1
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: OpenBB package with core functionality
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.14.2:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.137.2:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=6.8.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.12.3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.13.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.0.0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.29:www/py-python-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.34.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.15:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=2.0.0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uuid7>=0.1.0:devel/py-uuid7@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.48.0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=15.0:devel/py-websockets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
