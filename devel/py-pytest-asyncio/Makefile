PORTNAME=	pytest-asyncio
DISTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_asyncio-${DISTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pytest support for asyncio
WWW=		https://pytest-asyncio.readthedocs.io/en/stable/ \
		https://github.com/pytest-dev/pytest-asyncio

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=8.2,1<9,1:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=6.2:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=5.7.1:devel/py-hypothesis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

# tests as of 1.1.0: 23 failed, 145 passed in 214.54s (0:03:34), see https://github.com/pytest-dev/pytest-asyncio/issues/1227

.include <bsd.port.mk>
