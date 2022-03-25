# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	cloudpickle
PORTVERSION=	2.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extended pickling support for Python objects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=0:www/py-tornado@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
# Need -s for https://github.com/cloudpipe/cloudpickle/issues/252
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=tests/cloudpickle_testpkg ${PYTHON_CMD} -m pytest -rs -s -v

.include <bsd.port.mk>
