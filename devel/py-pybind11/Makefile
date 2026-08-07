PORTNAME=	pybind11
DISTVERSION=	3.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Seamless interoperability between C++11 and Python
WWW=		https://pybind11.readthedocs.io/en/stable/ \
		https://github.com/pybind/pybind11

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=7,1:devel/py-pytest@${PY_FLAVOR} \
		cmake:devel/cmake

USES=		cmake:indirect python
USE_PYTHON=	pep517 concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${WRKSRC}/build/tests

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} cmake -S . -B build -D PYBIND11_TEST=ON && \
		${SETENV} ${TEST_ENV} cmake --build build --target pytest

# tests as of 3.1.0: 1319 passed, 26 skipped, 3 xfailed, 1 xpassed in 14.95s

.include <bsd.port.mk>
