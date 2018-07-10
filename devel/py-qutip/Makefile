# $FreeBSD$

PORTNAME=	qutip
DISTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum toolbox in python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.15:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mayavi>0:graphics/py-mayavi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.15:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils cython autoplist

do-test: # tests are broken: https://github.com/qutip/qutip/issues/891
	@${ECHO} "==> Running tests. Please note that tests require X11 display access."
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} -c "import qutip.testing as qt; qt.run();"

.include <bsd.port.mk>
