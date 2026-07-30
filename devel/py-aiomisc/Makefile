PORTNAME=	aiomisc
DISTVERSION=	18.0.26
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Miscellaneous utilities for asyncio
WWW=		https://docs.aiomisc.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiothreads>=1.0.0:devel/py-aiothreads@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>=6.0:devel/py-colorlog@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiomisc-pytest>=2.0.0:devel/py-aiomisc-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.11:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-asgi>=0.5.2:devel/py-aiohttp-asgi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>=4.0.2:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2024.6.2:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter>=2.0:sysutils/py-croniter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnslib>=0.9:dns/py-dnslib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.110:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.64:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio-reflection>=1.64:devel/py-grpcio-reflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio-tools>=1.64:devel/py-grpcio-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.0.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=14.0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subtests>=0.9.0:devel/py-pytest-subtests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}raven>=6.10.0:devel/py-raven@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12.6:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.3:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.27:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=0:www/py-yarl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ARGS=	--ignore=tests/test_carbon_service.py -p no:relaxed
PYTEST_IGNORED_TESTS=	test_grpc_service test_initializer test_bad_initializer
TEST_WRKDIR=	${WRKSRC}/tests

NO_ARCH=	yes

# tests as of 18.0.26: 495 passed, 4 deselected, 31 warnings

.include <bsd.port.mk>
