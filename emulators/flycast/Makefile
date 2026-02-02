PORTNAME=	flycast
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6
CATEGORIES=	emulators

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Multi-platform Sega Dreamcast emulator
WWW=		https://github.com/flyinghead/flycast

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asio>0:net/asio \
		websocketpp>0:devel/websocketpp
LIB_DEPENDS=	libchdr.so:devel/libchdr \
		libcurl.so:ftp/curl \
		libminiupnpc.so:net/miniupnpc \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++20-lang pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	flyinghead
GH_TUPLE=	GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:1d8f600fd424278486eade7ed3e877c99f0846b1:VulkanMemoryAllocator/core/deps/VulkanMemoryAllocator \
		OrangeFox86:DreamPicoPort-API:8ea3b90e508d4a27a6e3a9f111d88d690bff018c:DreamPicoPortAPI/core/deps/DreamPicoPort-API \
		RetroAchievements:rcheevos:926e4608f8dca7989267c787bbefb3ab1c835ac5:rcheevos/core/deps/rcheevos \
		herumi:xbyak:0d67fd1530016b7c56f3cd74b3fca920f4c3e2b4:xbyak/core/deps/xbyak \
		paullouisageneau:libjuice:5948a4162d37bc213d6051b67ee2876ccc5a99a6:libjuice/core/deps/libjuice \
		vinniefalco:LuaBridge:ade28532d998ada20048db7f5a649acaf66a4532:LuaBridge/core/deps/luabridge
USE_SDL=	sdl2

CMAKE_ON=	USE_HOST_LIBCHDR

OPTIONS_DEFINE=		DOCS LUA OPENMP VULKAN
OPTIONS_DEFAULT=	ALSA AO LUA OPENMP OSS VULKAN
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA AO OSS PULSEAUDIO

# building with lua support fails on i386, see also
# https://github.com/vinniefalco/LuaBridge/issues/302
OPTIONS_EXCLUDE_i386=	LUA

VULKAN_DESC=	Build with Vulkan support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CMAKE_BOOL=		USE_LIBAO

LUA_USES=		lua:52+
LUA_CMAKE_BOOL=		USE_LUA

OPENMP_CMAKE_BOOL=	USE_OPENMP

OSS_CMAKE_BOOL=		USE_OSS

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSEAUDIO

VULKAN_BUILD_DEPENDS=	glslang>0:graphics/glslang \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_CMAKE_BOOL=	USE_HOST_GLSLANG \
			USE_VULKAN

post-install-DOCS-on:
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
