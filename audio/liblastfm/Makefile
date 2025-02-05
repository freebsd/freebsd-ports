PORTNAME=	liblastfm
DISTVERSION=	1.1.0-46
DISTVERSIONSUFFIX=	-g2e8e40d
CATEGORIES=	audio
PKGNAMESUFFIX=	-qt6

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Qt C++ library for the Last.fm webservices
WWW=		https://github.com/drfiemost/liblastfm

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing compiler:c++17-lang pkgconfig qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	lastfm
USE_LDCONFIG=	yes
USE_QT=		base tools:build

CMAKE_OFF=		BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

OPTIONS_DEFINE=		FINGERPRINT
OPTIONS_DEFAULT=	FINGERPRINT
OPTIONS_SUB=		yes

FINGERPRINT_DESC=	Build the lastfm-fingerprint library
# We only need fftw3.h from math/fftw3; no need to install
FINGERPRINT_BUILD_DEPENDS=	${NONEXISTENT}:math/fftw3:patch
FINGERPRINT_LIB_DEPENDS=libsamplerate.so:audio/libsamplerate \
			libfftw3f.so:math/fftw3-float
FINGERPRINT_CMAKE_BOOL=	BUILD_FINGERPRINT
FINGERPRINT_CMAKE_ON=	-DLIBFFTW3_INCLUDE_DIR:PATH=`${MAKE} -C ${PORTSDIR}/math/fftw3 -VWRKSRC`/api

.include <bsd.port.mk>
