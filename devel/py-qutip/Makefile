PORTNAME=	qutip
DISTVERSION=	5.0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum toolbox in python
WWW=		https://qutip.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.9:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.32.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}
# the optional graphics/py-mayavi dependency is omitted because it is python-2.7 -only

USES=		python
USE_PYTHON=	autoplist cython3 cython3_run pep517

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/qutip/*/*${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/qutip/*/*/*${PYTHON_TAG}.so

do-test: # 3 tests fail, see https://github.com/qutip/qutip/issues/2190
	@${ECHO} "==> Running tests. Please note that tests require X11 display access."
	@cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
		${PYTHON_CMD} -c "import qutip.testing as qt; qt.run();"

.include <bsd.port.mk>
