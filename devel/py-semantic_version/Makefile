# Created by: Fukang Chen <loader@FreeBSD.org>
# $FreeBSD$

PORTNAME=	semantic_version
PORTVERSION=	2.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Python library provides a few tools to handle SemVer in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>0:www/py-django18@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	rbarrois
GH_PROJECT=	python-semanticversion

NO_ARCH=	yes

# Actually 2.7,3.4+
USES=		python:2.7+
USE_PYTHON=	autoplist concurrent distutils

do-test:
	@(cd ${TEST_WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
