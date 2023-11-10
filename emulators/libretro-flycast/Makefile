PORTNAME=	libretro-flycast
DISTVERSION=	0.20231025
CATEGORIES=	emulators games

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Standalone port of flycast to libretro
WWW=		https://github.com/flyinghead/flycast

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		gl cmake:noninja
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flyinghead
GH_PROJECT=	flycast
GH_TAGNAME=	8fb3def2d5cdd6adea00171ed720afb390cafd78
GH_TUPLE=	libsdl-org:SDL:cc016b0046d563287f0aa9f09b958b5e70d43696:SDL/core/deps/SDL \
		flyinghead:libchdr:925400c4c4b67bafdff8dfad9a1474b22d980777:libchdr/core/deps/libchdr \
		vinniefalco:LuaBridge:fab7b33b896a42dcc865ba5ecdbacd9f409137f8:LuaBridge/core/deps/luabridge \
		flyinghead:mingw-breakpad:1ab24bcc817ebe629bf77daa53529d02361cb1e9:mingw_breakpad/core/deps/breakpad \
		KhronosGroup:Vulkan-Headers:85c2334e92e215cce34e8e0ed8b2dce4700f4a50:Vulkan_Headers/core/deps/Vulkan-Headers \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:6eb62e1515072827db992c2befd80b71b2d04329:VulkanMemoryAllocator/core/deps/VulkanMemoryAllocator \
		KhronosGroup:glslang:76b52ebf77833908dc4c0dd6c70a9c357ac720bd:glslang/core/deps/glslang \
		google:oboe:8740d0fc321a55489dbbf6067298201b7d2e106d:oboe/core/deps/oboe \
		vkedwardli:Syphon-Framework:486dd8e4ef3bead482ea26de99770f4389e24e37:Syphon_Framework/core/deps/Syphon \
		vkedwardli:Spout2:ce94918ea3561b936405e7f68b6754d975ed2e8f:Spout2/core/deps/Spout

USE_GL+=	gl
CMAKE_ARGS=     -DLIBRETRO=ON \
		-DCMAKE_POSITION_INDEPENDENT_CODE=TRUE \
		-DCMAKE_BUILD_TYPE=Release

.include <bsd.port.pre.mk>

PLIST_FILES=	lib/libretro/flycast_libretro.so

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/lib/libretro;
	${INSTALL_LIB} ${BUILD_WRKSRC}/flycast_libretro.so \
		${STAGEDIR}/${PREFIX}/lib/libretro/flycast_libretro.so;

.include <bsd.port.post.mk>
