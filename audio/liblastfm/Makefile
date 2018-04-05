# Created by: Matt Tosto <datahead4@gmail.com>
# $FreeBSD$

PORTNAME=	liblastfm
PORTVERSION=	1.0.9
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Qt C++ library for the Last.fm webservices

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	lastfm
USE_LDCONFIG=	yes
USE_QT4=	corelib dbus network sql xml \
		moc_build qmake_build rcc_build

CMAKE_ON=	BUILD_WITH_QT4

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

TEST_USE=		QT4=qtestlib_build
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TARGET=		test

.include <bsd.port.mk>
