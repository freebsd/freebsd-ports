PORTNAME=	libremidi
DISTVERSIONPREFIX=	v
DISTVERSION=	5.3.1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern C++ MIDI real-time & file I/O library
WWW=		https://github.com/jcelerier/libremidi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing compiler:c++20-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	jcelerier

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	LIBREMIDI_TESTS
CMAKE_ARGS=	-DFETCHCONTENT_TRY_FIND_PACKAGE_MODE=ALWAYS
CMAKE_TESTING_ON=	LIBREMIDI_TESTS

OPTIONS_DEFINE=		JACK
OPTIONS_DEFAULT=	JACK

.if exists(/usr/include/sys/eventfd.h) && exists(/usr/include/sys/timerfd.h)
OPTIONS_DEFINE+=	ALSA
OPTIONS_DEFAULT+=	ALSA # ALSA support requires libalsa, sys/eventfd.h, sys/timerfd.h

ALSA_CMAKE_OFF=		-DLIBREMIDI_NO_ALSA=ON
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
.else
CMAKE_ON+=		LIBREMIDI_NO_ALSA
.endif

JACK_CMAKE_OFF=		-DLIBREMIDI_NO_JACK=ON
JACK_LIB_DEPENDS=	libjack.so:audio/jack

# This library can also be used as a header-only library

# tests as of 5.3.1: 71% tests passed, 2 tests failed out of 7, see https://github.com/celtera/libremidi/issues/144

.include <bsd.port.mk>
