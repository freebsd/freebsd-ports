# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>

PORTNAME=	play
PORTVERSION=	0.38.0.20210320
PORTREVISION=	2
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
GH_TAGNAME=	3cd0a367b5e24c061a6310c68c9fa7f6b531ebd4 \
		10068b1fd39efa88fbfb2fe14e820eae552fb2a1:codegen \
		65baebea9ca9e7ce0631e71c8ede33f4e3d25a15:framework \
		e3e6669ecd40598b4e4adc1bc9297c6967f4c929:dependencies \
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
		USE_AOT_CACHE \
		ENABLE_AMAZON_S3
CMAKE_ARGS=	-DGIT_TAG=${GH_TAGNAME_DEFAULT} \
		-DGIT_DESCRIBE_RESULT=0

post-patch:
	@${REINPLACE_CMD} -e 's|execute_process(COMMAND git.*||g' \
		${WRKSRC}/CMakeLists.txt

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${WRKDIR}/.build/Source/ui_libretro/play_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
