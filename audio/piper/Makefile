PORTNAME=	piper
DISTVERSION=	2023.11.14
DISTVERSIONSUFFIX=	-2
CATEGORIES=	audio

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	A fast, local neural text to speech system
WWW=		https://rhasspy.github.io/piper-samples/

BUILD_DEPENDS=	${LOCALBASE}/include/spdlog/spdlog.h:devel/spdlog \
		${LOCALBASE}/include/piper-phonemize/phoneme_ids.hpp:audio/piper-phonemize

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog \
		libespeak-ng.so:audio/espeak-ng \
		libpiper_phonemize.so:audio/piper-phonemize \
		libonnxruntime.so:misc/onnxruntime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		compiler:c++17-lang cmake localbase pkgconfig tar:xz xorg
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	rhasspy
GH_TAGNAME=	38917ffd8c0e219c6581d73e07b30ef1d572fce1

#CMAKE_ARGS=	-DFMT_DIR=${PREFIX} \
#		-DSPDLOG_DIR=${PREFIX} \
#		-DPIPER_PHONEMIZE_DIR=${PREFIX}

.include <bsd.port.mk>
