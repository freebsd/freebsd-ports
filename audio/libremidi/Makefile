PORTNAME=	libremidi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern C++ MIDI real-time & file I/O library
WWW=		https://github.com/jcelerier/libremidi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.ModernMidi

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libjack.so:audio/jack
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	jcelerier

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	LIBREMIDI_TESTS
CMAKE_TESTING_ON=	LIBREMIDI_TESTS # 2 tests fail, see https://github.com/jcelerier/libremidi/issues/72

# This library can also be used as a header-only library

.include <bsd.port.mk>
