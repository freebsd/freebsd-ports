# $FreeBSD$

PORTNAME=	pytest
PORTVERSION=	3.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Simple powerful testing with Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py${SLAVE_SUFFIX}-setuptools_scm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py>=1.4.33:devel/py${SLAVE_SUFFIX}-py
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=1.13:devel/py-pytest-xdist \
		${PYTHON_PKGNAMEPREFIX}twisted>0:devel/py-twisted

NO_ARCH=	yes
USES+=		python
USE_PYTHON=	autoplist concurrent distutils

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
