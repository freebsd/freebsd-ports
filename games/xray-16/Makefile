PORTNAME=	xray-16
DISTVERSION=	2921-january-2025-rc1.20250720
CATEGORIES=	games

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Improved version of the X-Ray Engine (used for run S.T.A.L.K.E.R.)
WWW=		https://github.com/OpenXRay/xray-16/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis \
		libmimalloc.so:devel/mimalloc \
		liblzo2.so:archivers/lzo2

USES=		cmake jpeg openal sdl
USE_GITHUB=	yes
GH_ACCOUNT=	OpenXRay
GH_TAGNAME=	55a888c252cd815a0ea07439fc97cd954f2e34f0
GH_TUPLE=	GPUOpen-LibrariesAndSDKs:AGS_SDK:5d8812d:AGSSDK/Externals/AGS_SDK \
		OpenXRay:BugTrap:c619077b40ee6e7ad6ffc5a194a5d3583af8f78e:BugTrap/Externals/BugTrap \
		OpenXRay:GameSpy:61d061b4b3f860865f97e659e496e11704f61eb3:GameSpy/Externals/GameSpy \
		OpenXRay:LuaJIT:5a5cd82:LuaJIT/Externals/LuaJIT \
 		g-truc:gli:779b99ac6656e4d30c3b24e96e0136a59649a869:gli/Externals/gli \
		OpenXRay:luabind-deboostified:dd3db67:luabind/Externals/luabind \
		ocornut:imgui:efe2b21:ocornut/Externals/imgui \
		DLTcollab:sse2neon:6abd463:sse2neon/Externals/sse2neon \
		pattonkan:sse2rvv:f3a1d7d:sse2rvv/Externals/sse2rvv \
		OpenXRay:xrLuaFix:67b77c92f49c766c7c180cc39ffdb12799f395d:xrLuaFix/Externals/xrLuaFix \
		OpenXRay:luafilesystem:314c0d0fe8f4676ef35ac8abf3731be8535812fb:luafilesystem/Externals/xrLuaFix/lfs \
		OpenXRay:lua-marshal:983a3bfd646486292daa9f2ec9b72409f86dc931:marsal/Externals/xrLuaFix/lua-marshal \
		OpenXRay:lua-pack:c1e5a149b571cc31069e7e3146e881c203bdd052:pack/Externals/xrLuaFix/lua-pack

USE_SDL=	sdl2
CMAKE_ON=	XRAY_USE_LUAJIT

post-patch:
	${REINPLACE_CMD} -e 's|^    COMMAND make clean$$|    COMMAND /bin/echo make clean|' \
		${WRKSRC}/Externals/LuaJIT-proj/CMakeLists.txt

.include <bsd.port.mk>
