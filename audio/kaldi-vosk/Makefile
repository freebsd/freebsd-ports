PORTNAME=	kaldi # kaldi-vosk is for audio/vosk-api
PORTVERSION=	g20231219
CATEGORIES=	audio # machine-learning
PKGNAMESUFFIX=	-vosk

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Kaldi speech recognition toolkit
WWW=		https://kaldi-asr.org/

LICENSE=	APACHE20

LIB_DEPENDS=	libcblas.so:math/cblas \
		libfst.so:math/openfst-vosk \
		liblapack.so:math/lapack

USES=		cmake compiler:c++17-lang localbase:ldflags python:build

USE_GITHUB=	yes
GH_ACCOUNT=	alphacep
GH_TAGNAME=	2b69aed # the vosk branch

LDFLAGS+=	-lcblas -llapack

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	KALDI_BUILD_TEST
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD} \
		-DKALDI_VERSION=${PORTVERSION}

post-extract:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
