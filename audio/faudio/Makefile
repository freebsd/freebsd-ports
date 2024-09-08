PORTNAME=	FAudio
DISTVERSION=	24.08
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Accuracy-focused XAudio reimplementation
WWW=		https://fna-xna.github.io/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c11 sdl
USE_SDL=	sdl2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	FNA-XNA

PLIST_SUB=	SOVERSION=${DISTVERSION:S,., ,g:[1..2]:ts.}

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} \
		-DBUILD_TESTS=ON -DBUILD_UTILS=ON ${CMAKE_SOURCE_PATH} && \
		${DO_MAKE_BUILD} ${ALL_TARGET}
	@${SETENVI} SDL_AUDIODRIVER=dummy ${BUILD_WRKSRC}/faudio_tests

.include <bsd.port.mk>
