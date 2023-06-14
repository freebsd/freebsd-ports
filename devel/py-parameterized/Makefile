PORTNAME=	parameterized
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Parameterized testing with any Python test framework
WWW=		https://github.com/wolever/parameterized

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist nose nose2 pep517 pytest unittest2

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
