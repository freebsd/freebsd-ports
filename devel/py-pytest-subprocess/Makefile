PORTNAME=	pytest-subprocess
DISTVERSION=	1.5.2
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pytest plugin to fake subprocess for pytest
WWW=		https://github.com/aklajnert/pytest-subprocess

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=4.0.0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.12:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.15.1:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 2 tests fail, see https://github.com/aklajnert/pytest-subprocess/issues/123

USE_GITHUB=	yes
GH_ACCOUNT=	aklajnert

NO_ARCH=	yes

.include <bsd.port.mk>
