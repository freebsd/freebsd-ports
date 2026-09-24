PORTNAME=	qutip
DISTVERSION=	5.3.1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum toolbox in python
WWW=		https://qutip.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.9:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.23.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.9.2:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}
TEST_DEPENDS=	# tests need missing loky, and many optional dependencies, need extra work

USES=		python
USE_PYTHON=	autoplist cython cython_run pep517

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

do-test: # tests have missing deps, need more work
	@${ECHO} "==> Running tests. Please note that tests require X11 display access."
	@cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
		${PYTHON_CMD} -c "import qutip.testing as qt; qt.run();"

.include <bsd.port.mk>
