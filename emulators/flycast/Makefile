PORTNAME=	flycast
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7
CATEGORIES=	emulators

MAINTAINER=	bsdcode@disroot.org
COMMENT=	Multi-platform Sega Dreamcast emulator
WWW=		https://github.com/flyinghead/flycast

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asio130>0:net/asio130 \
		glm>0:math/glm \
		nlohmann-json>0:devel/nlohmann-json \
		stb>0:devel/stb \
		websocketpp>0:devel/websocketpp

LIB_DEPENDS=	libchdr.so:devel/libchdr \
		libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libminiupnpc.so:net/miniupnpc \
		libxxhash.so:devel/xxhash \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++20-lang pkgconfig sdl

USE_GITHUB=	yes
GH_ACCOUNT=	flyinghead
GH_TUPLE=	GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:3aa921224c154a0d2c43912bc88e1c42ce1f7607:VulkanMemoryAllocator/core/deps/VulkanMemoryAllocator \
		Grumbel:tinycmmc:50c49bf8a45f7c5ddb0c5f838a0fd6a00845a04d:tinycmmc/core/deps/tinygettext/external/tinycmmc \
		OrangeFox86:DreamPicoPort-API:06ad02fcaaf79bf349c4c6985a4df2dd63349825:DreamPicoPortAPI/core/deps/DreamPicoPort-API \
		RetroAchievements:rcheevos:f1417fbf2236936e8334533628b2948dfa4a46d0:rcheevos/core/deps/rcheevos \
		flyinghead:tinygettext:41572a67f96013691685a38f0032f3c97aa34f79:tinygettext/core/deps/tinygettext \
		herumi:xbyak:0d67fd1530016b7c56f3cd74b3fca920f4c3e2b4:xbyak/core/deps/xbyak \
		paullouisageneau:libjuice:f09cf92522de0b619a63d55d007b5466c7c14ad1:libjuice/core/deps/libjuice \
		vinniefalco:LuaBridge:ade28532d998ada20048db7f5a649acaf66a4532:LuaBridge/core/deps/luabridge

USE_SDL=	sdl2

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Git \
		USE_HOST_LIBCHDR

CFLAGS+=	-DGLM_ENABLE_EXPERIMENTAL \
		-I${LOCALBASE}/include/nlohmann \
		-I${LOCALBASE}/include/stb

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/dirent \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/glm \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/implot \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/json \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/libretro-common \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/libunwind \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/libzip \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/miniupnpc \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/stb \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/core/deps/xxHash \
			--no-same-owner --no-same-permissions

OPTIONS_DEFINE=		DOCS LIBCDIO LUA OPENMP VULKAN
OPTIONS_DEFAULT=	ALSA AO LIBCDIO LUA OPENMP OSS VULKAN
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA AO OSS PULSEAUDIO
# https://github.com/vinniefalco/LuaBridge/issues/302
OPTIONS_EXCLUDE_i386=	LUA

LIBCDIO_DESC=	CDROM support via libcdio

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CMAKE_BOOL=		USE_LIBAO

LIBCDIO_LIB_DEPENDS=	libcdio.so:sysutils/libcdio
LIBCDIO_CMAKE_BOOL=	USE_LIBCDIO

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

.include <bsd.port.pre.mk>

# FreeBSD < 15: libusb lacks required APIs
.if ${OSVERSION} < 1500000
CMAKE_OFF+=	USE_DREAMPICOPORT
.else
CMAKE_ON+=	USE_DREAMPICOPORT
.endif

post-install-DOCS-on:
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
