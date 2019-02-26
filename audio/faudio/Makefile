# $FreeBSD$

PORTNAME=	FAudio
DISTVERSION=	19.02-23
DISTVERSIONSUFFIX=	-ge5c9c20
CATEGORIES=	audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Accuracy-focused XAudio reimplementation

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		cmake compiler:c11 sdl
USE_GITHUB=	yes
GH_ACCOUNT=	FNA-XNA
USE_LDCONFIG=	yes
USE_SDL=	sdl2

CMAKE_ON=	FFMPEG

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
		-DBUILD_TESTS=ON -DBUILD_UTILS=ON ${CMAKE_SOURCE_PATH} && \
		${DO_MAKE_BUILD} ${ALL_TARGET}
	@${SETENV} SDL_AUDIODRIVER=dummy ${BUILD_WRKSRC}/faudio_tests

.include <bsd.port.mk>
