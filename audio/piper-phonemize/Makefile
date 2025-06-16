PORTNAME=	piper-phonemize
DISTVERSION=	2023.11.14
DISTVERSIONSUFFIX=	-4
CATEGORIES=	audio

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	A fast, local neural text to speech system
WWW=		https://rhasspy.github.io/piper-samples/

LIB_DEPENDS=	libespeak-ng.so:audio/espeak-ng \
		libonnxruntime.so:misc/onnxruntime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		compiler:c++17-lang cmake pkgconfig tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	rhasspy

CMAKE_ARGS=	-DESPEAK_NG_DIR=${PREFIX} \
		-DONNXRUNTIME_DIR=${PREFIX}

post-stage:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' ${FILESDIR}/piper_phonemize.pc \
		> ${STAGEDIR}${PREFIX}/libdata/pkgconfig/piper_phonemize.pc

.include <bsd.port.mk>
