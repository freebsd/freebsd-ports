PORTNAME=	serializable
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no test files
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Base class with serialization helpers for user-defined Python objects
WWW=		https://github.com/openvax/serializable

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typechecks>=0.0.2:devel/py-typechecks@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	openvax

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKDIR=	${WRKSRC}/tests

NO_ARCH=	yes

# tests as of 1.3.1: 100 passed, 2 warnings in 0.83s

.include <bsd.port.mk>
