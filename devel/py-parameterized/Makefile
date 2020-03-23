# $FreeBSD$

PORTNAME=	parameterized
PORTVERSION=	0.7.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Parameterized testing with any Python test framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose2>0:devel/py-nose2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unittest2>0:devel/py-unittest2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=yes

do-test:
	cd ${WRKSRC}; rc=0; \
	${PYTHON_CMD} -m nose || rc=1; \
	${PYTHON_CMD} -m nose2 || rc=1; \
	${PYTHON_CMD} -m pytest || rc=1; \
	${PYTHON_CMD} -m unittest || rc=1; \
	${PYTHON_CMD} -m unittest2 || rc=1; \
	exit $$rc

.include <bsd.port.mk>
