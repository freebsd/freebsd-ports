PORTNAME=	libremidi
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern C++ MIDI real-time & file I/O library
WWW=		https://github.com/jcelerier/libremidi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libjack.so:audio/jack
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing compiler:c++20-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	jcelerier

CMAKE_ON=	BUILD_SHARED_LIBS \
		LIBREMIDI_NO_ALSA
CMAKE_OFF=	LIBREMIDI_TESTS
CMAKE_TESTING_ON=	LIBREMIDI_TESTS

# test fail to configure: https://github.com/jcelerier/libremidi/issues/84
# before that was: 2 tests fail, see https://github.com/jcelerier/libremidi/issues/72

# This library can also be used as a header-only library

.include <bsd.port.mk>
