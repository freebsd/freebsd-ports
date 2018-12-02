# Created by: Matt Tosto <datahead4@gmail.com>
# $FreeBSD$

PORTNAME=	liblastfm
DISTVERSION=	1.0.9-5
DISTVERSIONSUFFIX=	-g4433165
CATEGORIES=	audio
PKGNAMESUFFIX=	-${SLAVE}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Qt C++ library for the Last.fm webservices

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	lastfm
USE_LDCONFIG=	yes

SLAVE?=		qt4
.if ${SLAVE} == qt4
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES+=		qt:4
USE_QT=		corelib dbus network sql xml \
		moc_build qmake_build rcc_build
CMAKE_ON+=	BUILD_WITH_QT4
.else
USES+=		qt:5
USE_QT=		core dbus network sql xml \
		buildtools_build qmake_build
CMAKE_OFF+=	BUILD_WITH_QT4
QTVER_SUFFIX=	5
.endif

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

.if ${SLAVE} == qt4
TEST_USES=	qt:4 qt:5
TEST_USE=		QT=qtestlib_build
.else
TEST_USE=		QT=testlib_build
.endif
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
