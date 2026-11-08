PORTNAME=	pytest-services
DISTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Fixtures and utility functions to run service processes for pytest
WWW=		https://github.com/pytest-dev/pytest-services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=8:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zc.lockfile>=2.0:devel/py-zc.lockfile@${PY_FLAVOR}
# tests: 5 passed, 1 skipped
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>=0:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mysqlclient>=0:databases/py-mysqlclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylibmc>=0:databases/py-pylibmc@${PY_FLAVOR} \
		memcached:databases/memcached \
		Xvfb:x11-servers/xorg-server@xvfb

USES=		pytest python
USE_PYTHON=	autoplist pep517
PYTEST_ARGS=	-p no:black -p no:markdown

TEST_ENV=	USER=${USER}

NO_ARCH=	yes

OPTIONS_DEFINE=	MEMCACHED

MEMCACHED_DESC=		Enables memcached support
MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylibmc>=0:databases/py-pylibmc@${PY_FLAVOR}

.include <bsd.port.mk>
