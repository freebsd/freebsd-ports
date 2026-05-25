PORTNAME=	pykep
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	astro python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for pykep, library for astrodynamics research
WWW=		https://github.com/esa/pykep

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libkep3.so:astro/pykep
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}heyoka>0:math/py-heyoka@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygmo2>0:science/py-pygmo2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sgp4>0:astro/py-sgp4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spiceypy>0:astro/py-spiceypy@${PY_FLAVOR}

USES=		cmake compiler:c++23-lang localbase:ldflags python
USE_CXXSTD=	c++23
USE_PYTHON=	flavors pytest

CMAKE_OFF=	kep3_BUILD_CPP_LIBRARY
CMAKE_ON=	kep3_BUILD_PYTHON_BINDINGS

USE_GITHUB=	yes
GH_ACCOUNT=	esa

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/pykep

pre-test:
	@${CP} ${WRKDIR}/.build/pykep/core${PYTHON_TAG}.so \
		${WRKSRC}/pykep/core${PYTHON_TAG}.so

TEST_ARGS=	-p no:xdist

# tests as of 3.0.0: 89 passed in 10.76s

.include <bsd.port.mk>
