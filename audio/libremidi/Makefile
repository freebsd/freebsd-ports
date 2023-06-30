PORTNAME=	libremidi
DISTVERSION=	g20230630
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern C++ MIDI real-time & file I/O library
WWW=		https://github.com/jcelerier/libremidi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.ModernMidi

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libjack.so:audio/jack

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	jcelerier
GH_TAGNAME=	c4833ef

CMAKE_ON=	BUILD_SHARED_LIBS

# This library can also be used as a header-only library

.include <bsd.port.mk>
