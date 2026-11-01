PORTNAME=	play
PORTVERSION=	0.77
CATEGORIES=	games
PKGNAMEPREFIX=	libretro-

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Play! - PlayStation 2 Emulator
WWW=		https://purei.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libicuuc.so:devel/icu

USES=		cmake sqlite:3 ssl gl compiler:c++17-lang
USE_GL=		egl gl glew glu
USE_LDCONFIG=	yes
USE_CXXSTD=	c++17

USE_GITHUB=	yes
GH_ACCOUNT=	jpd002 \
		jpd002:altkit \
		jpd002:codegen \
		jpd002:dependencies \
		jpd002:framework \
		jpd002:nuanceur \
		jpd002:libchdr \
		gulrak:dependencies_ghc_filesystem \
		Cyan4973:dependencies_xxhash \
		meta:dependencies_zstd
GH_PROJECT=	Play- \
		AltKit:altkit \
		Play--CodeGen:codegen \
		Play-Dependencies:dependencies \
		Play--Framework:framework \
		Nuanceur:nuanceur \
		libchdr:libchdr \
		filesystem:dependencies_ghc_filesystem \
		xxHash:dependencies_xxhash \
		zstd:dependencies_zstd
GH_TAGNAME=	f799f60ef6fa8b9676b4102b7dfa169fb40b6c92:altkit \
		a5009f7dca062695b8e5aebbd71e67b4ddfa9251:codegen \
		8a5f6b1dea0b888b5a42b821e79470142bbea4e3:dependencies \
		587f278917acc0026bf5fc34b39f995fc26bd015:framework \
		d96578b5a18edc67a268ed4811f0a035c56de7a0:nuanceur \
		284e38b6e53e0a7270cc234934e45230ed915a25:libchdr \
		2a8b380f8d4e77b389c42a194ab9c70d8e3a0f1e:dependencies_ghc_filesystem \
		e626a72bc2321cd320e953a0ccf1584cad60f363:dependencies_xxhash \
		f8745da6ff1ad1e7bab384bd1f9d742439278e99:dependencies_zstd
GH_SUBDIR=	deps/AltKit:altkit \
		deps/CodeGen:codegen \
		deps/Dependencies:dependencies \
		deps/Framework:framework \
		deps/Nuanceur:nuanceur \
		deps/libchdr:libchdr \
		deps/Dependencies/ghc_filesystem:dependencies_ghc_filesystem \
		deps/Dependencies/xxHash:dependencies_xxhash \
		deps/Dependencies/zstd:dependencies_zstd

PLIST_FILES=	lib/libretro/play_libretro.so

CMAKE_ON=	BUILD_LIBRETRO_CORE
CMAKE_OFF=	BUILD_AOT_CACHE \
		BUILD_PLAY \
		BUILD_PSFPLAYER \
		BUILD_TESTS \
		USE_AOT_CACHE \
		USE_GLES \
		ENABLE_AMAZON_S3
CMAKE_ARGS=	-DOpenGL_GL_PREFERENCE="GLVND"

post-patch:
	@${REINPLACE_CMD} \
		-e 's|find_package(Git)||g' \
		-e 's|execute_process(COMMAND git.*||g' \
		${WRKSRC}/CMakeLists.txt

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${BUILD_WRKSRC}/Source/ui_libretro/play_libretro.so ${STAGEDIR}/${PREFIX}/lib/libretro;

.include <bsd.port.mk>
