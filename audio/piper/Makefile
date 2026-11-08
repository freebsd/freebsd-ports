PORTNAME=	piper
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Fast, local text to speech system
WWW=		https://github.com/OHF-Voice/piper1-gpl

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libespeak-ng.so:audio/espeak-ng \
		libonnxruntime.so:misc/onnxruntime

USES=		cmake compiler:c++17-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	OHF-Voice
GH_PROJECT=	piper1-gpl

USE_LDCONFIG=	yes

# Only the C++ library and command line interface are built.
CMAKE_SOURCE_PATH=	${WRKSRC}/libpiper

PLIST_FILES=	bin/piper \
		include/piper.h \
		lib/libpiper.so \
		lib/libpiper.so.1 \
		lib/libpiper.so.${PORTVERSION}

.include <bsd.port.mk>
