PORTNAME=	FAudio
DISTVERSION=	26.09
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Accuracy-focused XAudio reimplementation
WWW=		https://fna-xna.github.io/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c11 sdl
USE_LDCONFIG=	yes
USE_SDL=	sdl3

USE_GITHUB=	yes
GH_ACCOUNT=	FNA-XNA

CMAKE_TESTING_ON=	BUILD_TESTS \
			BUILD_UTILS
CMAKE_TESTING_TARGET=

TEST_ENV=	SDL_AUDIODRIVER=dummy

PLIST_SUB=	SOVERSION=${DISTVERSION:S,., ,g:[1..2]:ts.}

post-test:
	@${SETENVI} ${WRK_ENV} ${TEST_ENV} ${BUILD_WRKSRC}/faudio_tests

.include <bsd.port.mk>
