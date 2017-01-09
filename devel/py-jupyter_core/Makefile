# $FreeBSD$

PORTNAME=	jupyter_core
PORTVERSION=	4.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Jupyter core package

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}testpath>=0:devel/py-testpath

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes
TEST_ENV=	${MAKE_ENV} LANG=en_US.UTF-8

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYTHON_VER})

.include <bsd.port.mk>
