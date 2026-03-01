PORTNAME=	nanobind
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny and efficient C++/Python bindings (C++ version)
WWW=		https://nanobind.readthedocs.io/en/latest/ \
		https://github.com/wjakob/nanobind

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	robin-map>0:devel/robin-map
RUN_DEPENDS=	robin-map>0:devel/robin-map
TEST_DEPENDS=	eigen>0:math/eigen3 \
		gmake:devel/gmake \
		pytest:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jax>0:math/py-jax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
#		${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVORA} # tensorflow tests crash the python process

USES=		cmake:testing localbase python:test

USE_GITHUB=	yes
GH_ACCOUNT=	wjakob

CMAKE_ARGS=	-DNB_INSTALL_DATADIR=${PREFIX}
CMAKE_ON=	NB_CREATE_INSTALL_RULES
CMAKE_OFF=	NB_USE_SUBMODULE_DEPS \
		NB_TEST_FREE_THREADED \
		NB_TEST \
		CMAKE_SKIP_INSTALL_RULES
CMAKE_TESTING_ON=	NB_TEST
CMAKE_TESTING_TARGET=	copy-tests
CXXFLAGS+=	-I${WRKSRC}/include \
		-I${PYTHON_INCLUDEDIR}

INSTALL_TARGET=	install

TEST_WRKSRC=	${BUILD_WRKSRC}/tests

NO_ARCH=	yes

post-install:
	# workaround for https://github.com/wjakob/nanobind/issues/1300
	@${RM} \
		${STAGEDIR}${PREFIX}/cmake/darwin-ld-cpython.sym \
		${STAGEDIR}${PREFIX}/cmake/darwin-ld-pypy.sym \
		${STAGEDIR}${PREFIX}/cmake/darwin-python-path.py
	# correct path to the src directory in cmake file
	@${REINPLACE_CMD} -e 's|$${NB_DIR}/src/|${DATADIR}/src/|g' \
		${STAGEDIR}${PREFIX}/cmake/nanobind-config.cmake

post-test:
	@cd ${TEST_WRKSRC} && \
		pytest .

# tests as of 2.12.0:
# Results (41.59s):
#          2 failed
#       1486 passed
#         19 skipped
#          2 warnings

# cmake installs files into non-standard locations, see https://github.com/wjakob/nanobind/issues/810
# hostile upstream, do not create bug reports

.include <bsd.port.mk>
