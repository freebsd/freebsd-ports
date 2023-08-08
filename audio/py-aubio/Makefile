PORTREVISION=	2
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python bindings for aubio music analysis

LIB_DEPENDS=	libaubio.so:audio/aubio
BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	sox:audio/sox

USES+=		python
USE_PYTHON=	autoplist concurrent distutils pytest

MASTERDIR=	${.CURDIR}/../../audio/aubio
SLAVEPORT=	py
PLIST=		${.CURDIR}/pkg-plist

pre-test:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} create_test_sounds)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_aubio*.so

.include "${MASTERDIR}/Makefile"
