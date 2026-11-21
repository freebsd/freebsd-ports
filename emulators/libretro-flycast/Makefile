PORTNAME=	libretro-flycast
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7
CATEGORIES=	emulators games

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Standalone port of flycast to libretro
WWW=		https://github.com/flyinghead/flycast

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		gl cmake:noninja

USE_GITHUB=	yes
GH_ACCOUNT=	flyinghead
GH_PROJECT=	flycast
GH_TUPLE=	Grumbel:tinycmmc:50c49bf8a45f7c5ddb0c5f838a0fd6a00845a04d:tinycmmc/core/deps/tinygettext/external/tinycmmc \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:1d8f600fd424278486eade7ed3e877c99f0846b1:VulkanMemoryAllocator/core/deps/VulkanMemoryAllocator \
		KhronosGroup:Vulkan-Headers:b5c8f996196ba4aa6d8f97e52b5d3b6e70f7e4e2:Vulkan_Headers/core/deps/Vulkan-Headers \
		KhronosGroup:glslang:fc9889c889561c5882e83819dcaffef5ed45529b:glslang/core/deps/glslang \
		RetroAchievements:rcheevos:3106e6d3d274b63c59976cb07dda94a292ab45ca:rcheevos/core/deps/rcheevos \
		flyinghead:libchdr:5f82799f2c8cad1e9cd26d39a0f8d36369a5534b:libchdr/core/deps/libchdr \
		flyinghead:tinygettext:41572a67f96013691685a38f0032f3c97aa34f79:tinygettext/core/deps/tinygettext \
		herumi:xbyak:0d67fd1530016b7c56f3cd74b3fca920f4c3e2b4:xbyak/core/deps/xbyak \
		paullouisageneau:libjuice:77daa8befd828046169adbb012d8de928bfdcdd4:libjuice/core/deps/libjuice \
		vinniefalco:LuaBridge:5d21e35633a1f87ed08af115b07d3386096f792b:LuaBridge/core/deps/luabridge \
		flyinghead:asio:d3402006e84efb6114ff93e4f2b8508412ed80d5:asio/core/deps/asio \
		zaphoyd:websocketpp:1b11fd301531e6df35a6107c1e8665b1e77a2d8e:websocketpp/core/deps/websocketpp

USE_GL+=	gl
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DLIBRETRO=ON \
		-DCMAKE_POSITION_INDEPENDENT_CODE=TRUE \
		-DCMAKE_BUILD_TYPE=Release
CMAKE_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Git

PLIST_FILES=	lib/libretro/flycast_libretro.so

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/libretro
	${INSTALL_LIB} ${BUILD_WRKSRC}/flycast_libretro.so \
		${STAGEDIR}${PREFIX}/lib/libretro/flycast_libretro.so

.include <bsd.port.mk>
