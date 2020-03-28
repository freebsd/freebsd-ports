# $FreeBSD$

PORTNAME=	fakeredis
PORTVERSION=	1.3.0
CATEGORIES=	databases
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fake version of databases/py-redis for unit testing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=0<3.5:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.1.0:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest<5.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov<3.0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} test_fakeredis.py

.include <bsd.port.mk>
