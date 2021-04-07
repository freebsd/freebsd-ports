PORTNAME=	liblastfm
DISTVERSION=	1.0.9-5
PORTREVISION=	2
DISTVERSIONSUFFIX=	-g4433165
CATEGORIES=	audio
PKGNAMESUFFIX=	-qt5

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Qt C++ library for the Last.fm webservices

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	lastfm
USE_LDCONFIG=	yes
USE_QT=		core dbus network sql xml \
		buildtools_build qmake_build
CMAKE_OFF=	BUILD_WITH_QT4
QTVER_SUFFIX=	5

PLIST_SUB=	QTVER_SUFFIX="${QTVER_SUFFIX}"

OPTIONS_DEFINE=		FINGERPRINT TEST
OPTIONS_DEFAULT=	FINGERPRINT
OPTIONS_SUB=		yes

FINGERPRINT_DESC=	Build the lastfm-fingerprint library
FINGERPRINT_LIB_DEPENDS=libsamplerate.so:audio/libsamplerate \
			libfftw3f.so:math/fftw3-float
FINGERPRINT_CMAKE_BOOL=	BUILD_FINGERPRINT
# We only need fftw3.h from math/fftw3; no need to install
FINGERPRINT_BUILD_DEPENDS=	${NONEXISTENT}:math/fftw3:patch
FINGERPRINT_CMAKE_ON=	-DLIBFFTW3_INCLUDE_DIR:PATH=`${MAKE} -C ${PORTSDIR}/math/fftw3 -VWRKSRC`/api

TEST_USE=		QT=testlib_build
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
