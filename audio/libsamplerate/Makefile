PORTNAME=	libsamplerate
DISTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/libsndfile/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Secret Rabbit Code: a Sample Rate Converter for audio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe pkgconfig tar:xz

CPE_VENDOR=	${CPE_PRODUCT}_project

USE_LDCONFIG=	yes

TEST_TARGET=	test

CMAKE_ON=	BUILD_SHARED_LIBS LIBSAMPLERATE_INSTALL

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

EXAMPLES_LIB_DEPENDS=		libsndfile.so:audio/libsndfile
EXAMPLES_CMAKE_BOOL=		LIBSAMPLERATE_EXAMPLES

TEST_LIB_DEPENDS=		libfftw3.so:math/fftw3 \
				libsndfile.so:audio/libsndfile
TEST_CMAKE_BOOL=		BUILD_TESTING

do-install-EXAMPLES-on:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/examples/timewarp-file ${STAGEDIR}${PREFIX}/bin/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/timewarp-file

.include <bsd.port.mk>
