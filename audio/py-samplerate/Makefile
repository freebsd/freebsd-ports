PORTNAME=	samplerate
DISTVERSION=	0.2.1
CATEGORIES=	audio
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for libsamplerate based on pybind11 and NumPy
WWW=		https://github.com/tuxu/python-samplerate

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		pybind11>0:devel/pybind11 \
		cmake:devel/cmake-core
LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake compiler:c++14-lang pkgconfig python
USE_PYTHON=	flavors pytest

TEST_WRKSRC=	${WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

PLIST_FILES=	${PYTHON_SITELIBDIR}/samplerate${PYTHON_TAG}.so

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/samplerate${PYTHON_TAG}.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
