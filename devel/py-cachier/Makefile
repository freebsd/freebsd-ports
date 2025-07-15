PORTNAME=	cachier
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Persistent/stale-free/local/cross-machine caching for Python functions
WWW=		https://github.com/python-cachier/cachier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}portalocker>=2.3.2:devel/py-portalocker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=2.3.1:devel/py-watchdog@${PY_FLAVOR}
# TEST_DEPENDS has 2 not-yet-ported dependencies: birch, pymongo-inmemory

USES=		python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	python-cachier

NO_ARCH=	yes

.include <bsd.port.mk>
