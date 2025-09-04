PORTNAME=	whisper.cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.6
CATEGORIES=	audio # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Port of OpenAI's Whisper model in C/C++
WWW=		https://github.com/ggerganov/whisper.cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libggml.so:misc/ggml

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ggerganov

LDFLAGS+=	-pthread

CMAKE_ON=	WHISPER_USE_SYSTEM_GGML
CMAKE_OFF=	WHISPER_BUILD_TESTS
CMAKE_TESTING_ON=	WHISPER_BUILD_TESTS \
			WHISPER_BUILD_EXAMPLES

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES # examples contain important user level programs
OPTIONS_SUB=		yes

EXAMPLES_CMAKE_BOOL=	WHISPER_BUILD_EXAMPLES

post-install:
	${INSTALL_SCRIPT} \
		${WRKSRC}/models/download-ggml-model.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-download-ggml-model.sh

# tests as of 1.7.6: 73% tests passed, 3 tests failed out of 11, see https://github.com/ggml-org/whisper.cpp/issues/3404

.include <bsd.port.mk>
