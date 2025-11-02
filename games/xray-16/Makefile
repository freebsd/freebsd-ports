PORTNAME=	xray-16
DISTVERSION=	2921-january-2025-rc1.20251014
CATEGORIES=	games

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Improved version of the X-Ray Engine (used for run S.T.A.L.K.E.R.)
WWW=		https://github.com/OpenXRay/xray-16/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	upstream only supports "x86, x64, ARM, ARM64, E2K (Elbrus 2000), PPC64LE"

SSE2NEON_ARCHS=	aarch64 armv7
BUILD_DEPENDS=	${SSE2NEON_ARCHS:M${ARCH}:S|${ARCH}|${LOCALBASE}/include/sse2neon.h:devel/sse2neon|}

LIB_DEPENDS=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis \
		libmimalloc.so:devel/mimalloc \
		liblzo2.so:archivers/lzo2 \
		libimgui.so:x11-toolkits/imgui

USES=		cmake jpeg localbase:ldflags openal sdl
USE_GITHUB=	yes
GH_ACCOUNT=	OpenXRay
GH_TAGNAME=	e836dd9e8453fc427d5cee9aa911bdb66b1c6eff
GH_TUPLE=	GPUOpen-LibrariesAndSDKs:AGS_SDK:5d8812d:AGSSDK/Externals/AGS_SDK \
		OpenXRay:GameSpy:3e43480:GameSpy/Externals/GameSpy \
		OpenXRay:LuaJIT:5a5cd82:LuaJIT/Externals/LuaJIT \
 		g-truc:gli:779b99ac6656e4d30c3b24e96e0136a59649a869:gli/Externals/gli \
		OpenXRay:luabind-deboostified:8da131b:luabind/Externals/luabind \
		pattonkan:sse2rvv:373f788:sse2rvv/Externals/sse2rvv \
		OpenXRay:xrLuaFix:0e89050:xrLuaFix/Externals/xrLuaFix \
		OpenXRay:luafilesystem:314c0d0fe8f4676ef35ac8abf3731be8535812fb:luafilesystem/Externals/xrLuaFix/lfs \
		OpenXRay:lua-marshal:983a3bfd646486292daa9f2ec9b72409f86dc931:marsal/Externals/xrLuaFix/lua-marshal \
		OpenXRay:lua-pack:c1e5a149b571cc31069e7e3146e881c203bdd052:pack/Externals/xrLuaFix/lua-pack
USE_SDL=	sdl2

CMAKE_ON=	XRAY_USE_LUAJIT
CFLAGS+=	-DIMGUI_DEFINE_MATH_OPERATORS \
		-DIMGUI_DISABLE_OBSOLETE_KEYIO \
		-DIMGUI_DISABLE_OBSOLETE_FUNCTIONS

_IMGUI=		Layers/xrRenderPC_GL/CMakeLists.txt \
		xrEngine/CMakeLists.txt \
		xrGame/CMakeLists.txt \
		xrUICore/CMakeLists.txt

_SSE2NEON=	xrCDB/xrCDB_ray.cpp \
		xrCDB/ISpatial_q_ray.cpp \
		xrParticles/noise.cpp \
		xrParticles/particle_actions_collection.cpp \
		xrCore/Threading/TaskManager.cpp \
		Layers/xrRender/ParticleEffect.cpp \
		Layers/xrRender/DetailManager.cpp

post-patch:
	${REINPLACE_CMD} -e 's|^    COMMAND make clean$$|    COMMAND /bin/echo make clean|' \
		${WRKSRC}/Externals/LuaJIT-proj/CMakeLists.txt
	${REINPLACE_CMD} -e 's|xrImGui|imgui|' \
		${_IMGUI:S|^|${WRKSRC}/src/|}
	${REINPLACE_CMD} -e 's|"sse2neon/sse2neon.h"|<sse2neon.h>|' \
		${_SSE2NEON:S|^|${WRKSRC}/src/|}

.include <bsd.port.mk>
