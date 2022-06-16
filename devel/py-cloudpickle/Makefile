# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	cloudpickle
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extended pickling support for Python objects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes
TEST_ARGS=	-s # https://github.com/cloudpipe/cloudpickle/issues/252
TEST_ENV=	PYTHONPATH=tests/cloudpickle_testpkg

.include <bsd.port.mk>
