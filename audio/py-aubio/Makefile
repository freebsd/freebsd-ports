# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python bindings for aubio music analysis

LIB_DEPENDS=	libaubio.so:audio/aubio
BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	sox:audio/sox \
		${PYTHON_PKGNAMEPREFIX}nose2>=0.6.5:devel/py-nose2@${PY_FLAVOR}

USES+=		python
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${WRKSRC}/`ls -rtd build/lib.* | head -1`
TEST_TARGET=	test
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYSETUP}

MASTERDIR=	${.CURDIR}/../../audio/aubio
SLAVEPORT=	py
PLIST=		${.CURDIR}/pkg-plist

pre-test:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} create_test_sounds)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_aubio.so

.include "${MASTERDIR}/Makefile"
