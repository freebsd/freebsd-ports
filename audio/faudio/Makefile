PORTNAME=	FAudio
DISTVERSION=	25.03
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Accuracy-focused XAudio reimplementation
WWW=		https://fna-xna.github.io/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	sdl3 sdl2
FLAVOR?=	${FLAVORS:[1]}
sdl2_CONFLICTS_INSTALL=	${PORTNAME}-sdl3
sdl3_PKGNAMESUFFIX=	-sdl3
sdl3_CONFLICTS_INSTALL=	${PORTNAME}

USES=		cmake:testing compiler:c11 sdl
USE_LDCONFIG=	yes
USE_SDL=	${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	FNA-XNA

CMAKE_${"${FLAVOR:Msdl3}":?ON:OFF}=	BUILD_SDL3
# Tests will fail to build with the sdl2 flavor. Upstream dropped sdl2
# support in the utils needed for the tests starting with version 25.03.
CMAKE_TESTING_ON=	BUILD_TESTS \
			BUILD_UTILS
CMAKE_TESTING_TARGET=	# No internal target for running tests. Run via post-test.

TEST_ENV=	SDL_AUDIODRIVER=dummy

PLIST_SUB=	SOVERSION=${DISTVERSION:S,., ,g:[1..2]:ts.}

post-test:
	@${SETENVI} ${WRK_ENV} ${TEST_ENV} ${BUILD_WRKSRC}/faudio_tests

.include <bsd.port.mk>
