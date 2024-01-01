PORTNAME=	kaldi
PORTVERSION=	g20231112
PORTREVISION=	1
CATEGORIES=	audio # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Kaldi speech recognition toolkit
WWW=		https://kaldi-asr.org/

LICENSE=	APACHE20

LIB_DEPENDS=	libcblas.so:math/cblas \
		libfst.so:math/openfst \
		liblapack.so:math/lapack

USES=		cmake compiler:c++17-lang localbase:ldflags python:build

USE_GITHUB=	yes
GH_ACCOUNT=	kaldi-asr
GH_TAGNAME=	21ae411

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	KALDI_BUILD_TEST
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD} \
		-DKALDI_VERSION=${PORTVERSION}

post-extract:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
