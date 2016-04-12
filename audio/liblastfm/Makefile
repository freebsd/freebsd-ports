# Created by: Matt Tosto <datahead4@gmail.com>
# $FreeBSD$

PORTNAME=	liblastfm
PORTVERSION=	1.0.9
CATEGORIES=	audio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Qt C++ library for the Last.fm webservices

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libsamplerate.so:audio/libsamplerate

GH_ACCOUNT=	lastfm

USES=		cmake pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT4=	dbus network qtestlib sql xml \
		moc_build qmake_build rcc_build

CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=ON

OPTIONS_DEFINE=		FINGERPRINT TEST
OPTIONS_DEFAULT=	FINGERPRINT
OPTIONS_SUB=		yes
FINGERPRINT_DESC=	Build the lastfm-fingerprint library
FINGERPRINT_CMAKE_ON=	-DBUILD_FINGERPRINT:BOOL=ON
FINGERPRINT_CMAKE_OFF=	-DBUILD_FINGERPRINT:BOOL=OFF
TEST_CMAKE_ON=		-DBUILD_TESTS:BOOL=ON
TEST_CMAKE_OFF=		-DBUILD_TESTS:BOOL=OFF

.include <bsd.port.mk>
