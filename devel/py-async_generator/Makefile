# $FreeBSD$

PORTNAME=	async_generator
PORTVERSION=	1.10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tiny library to add async generators to Python 3.5

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APACHE2

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
