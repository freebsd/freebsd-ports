# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	play
PORTVERSION=	0.33.0.20201020
CATEGORIES=	games
PKGNAMEPREFIX=	libretro-

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Play! - PlayStation 2 Emulator

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

BROKEN_aarch64=	linker error: uunable to find library -lGLESv2

LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake ssl gl compiler:c++17-lang
USE_GL=		egl gl glew glu
USE_LDCONFIG=	yes
USE_CXXSTD=	c++17

USE_GITHUB=	yes
GH_ACCOUNT=	jpd002 \
		jpd002:codegen \
		jpd002:framework \
		jpd002:dependencies \
		gulrak:ghc_filesystem
GH_PROJECT=	Play- \
		Play--CodeGen:codegen \
		Play--Framework:framework \
		Play-Dependencies:dependencies \
		filesystem:ghc_filesystem
GH_TAGNAME=	80b31dd8c1583b2200ee6345c1047e901dcd54ed \
		e52d41b0c18132edf657225a422e6699c1d241c4:codegen \
		26314863b9af9fd2c492d6410a8fbe24701eabd2:framework \
		41b68c0dd63dee867e8519fca9b52970fc0c8ddf:dependencies \
		3605e869150032ffdd9eae3db93e12f8711a0c82:ghc_filesystem
GH_SUBDIR=	deps/CodeGen:codegen \
		deps/Framework:framework \
		deps/Dependencies:dependencies \
		deps/Dependencies/ghc_filesystem:ghc_filesystem

PLIST_FILES=	lib/libretro/play_libretro.so

CMAKE_ON=	BUILD_LIBRETRO_CORE
CMAKE_OFF=	BUILD_AOT_CACHE \
		BUILD_PLAY \
		BUILD_PSFPLAYER \
		BUILD_TESTS \
		ENABLE_AMAZON_S3
CMAKE_ARGS=	-DSHORT_HASH=${GH_TAGNAME_DEFAULT}

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKDIR}/.build/Source/ui_libretro/play_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
