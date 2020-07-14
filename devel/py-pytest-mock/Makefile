# $FreeBSD$

PORTNAME=	pytest-mock
PORTVERSION=	1.10.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/pytest-dev/${PORTNAME}/commit/
PATCHFILES=	b3badafebedea3605c90eb22a68adff2885a8bb0.patch:-p1

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Thin wrapper around the mock package for easier use with py.test

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.7:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs test_pytest_mock.py

.include <bsd.port.mk>
