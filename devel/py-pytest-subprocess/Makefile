PORTNAME=	pytest-subprocess
DISTVERSION=	1.6.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pytest plugin to fake subprocess for pytest
WWW=		https://github.com/aklajnert/pytest-subprocess

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=4.0.0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.12:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.15.1:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	aklajnert

PYTEST_BROKEN_TESTS=	test_documentation[README.rst] \
			test_documentation[docs/index.rst] # README/docs examples assume a `python` binary; see https://github.com/aklajnert/pytest-subprocess/issues/123
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin \
		-p pytest_subprocess.fixtures \
		-p pytest_rerunfailures \
		-p pytest_timeout \
		-p no:flaky

NO_ARCH=	yes

# tests as of 1.6.0: 159 passed, 4 skipped, 2 deselected in 10.06s

.include <bsd.port.mk>
