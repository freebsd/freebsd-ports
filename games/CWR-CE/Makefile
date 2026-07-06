PORTNAME=	CWR-CE
DISTVERSIONPREFIX=	v
DISTVERSION=	3.01
PORTREVISION=	2
CATEGORIES=	games

PATCH_SITES=	https://github.com/ocochard/CWR-CE/compare/
PATCHFILES=	9abbdf2769f3008d76c47ac0af219388ff0323dc..8fc693b2c6f85929e43975ef04df28818e740dba.patch:-p1

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Arma: Cold War Assault - Remastered Community Edition
WWW=		https://github.com/ofpisnotdead-com/CWR-CE

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	stb>0:devel/stb \
		${LOCALBASE}/include/CLI/CLI.hpp:devel/cli11 \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		${LOCALBASE}/lib/cmake/Catch2/Catch2Config.cmake:devel/catch2 \
		${LOCALBASE}/lib/cmake/glslang/glslang-config.cmake:graphics/glslang
LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libcurl.so:ftp/curl \
		libenkiTS.so:devel/enkits \
		libfmt.so:devel/libfmt \
		libfreetype.so:print/freetype2 \
		libimgui.so:x11-toolkits/imgui \
		libmimalloc.so:devel/mimalloc \
		libogg.so:audio/libogg \
		libopenal.so:audio/openal-soft \
		libopus.so:audio/opus \
		libSDL3.so:devel/sdl3 \
		libvulkan.so:graphics/vulkan-loader \
		libspdlog.so:devel/spdlog \
		libvorbis.so:audio/libvorbis \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++20-lang dos2unix gl localbase pkgconfig

DOS2UNIX_REGEX=	.*\.(c|h|cpp|hpp)
USE_GITHUB=	yes
GH_ACCOUNT=	ofpisnotdead-com
GH_PROJECT=	CWR-CE
GH_TAGNAME=	9abbdf2769f3008d76c47ac0af219388ff0323dc
USE_GL=		gl

SUB_FILES=	pkg-message

# Disable vcpkg toolchain wiring — find_package(... CONFIG REQUIRED) picks up
# system libraries from ${LOCALBASE}/lib/cmake instead.
CMAKE_ARGS=	-DVCPKG_MANIFEST_MODE=OFF \
		-DCMAKE_DISABLE_FIND_PACKAGE_VCPKG=ON

CMAKE_OFF=	POSEIDON_DISABLE_PCH POSEIDON_BUILD_FUZZERS

PLIST_FILES=	bin/PoseidonGame \
		bin/PoseidonGameDemo \
		bin/PoseidonServer \
		bin/PoseidonStudio \
		bin/PoseidonTetris \
		bin/PoseidonTools \
		bin/cwr-ce \
		bin/install-cwr-data

do-install:
	${INSTALL_PROGRAM} \
		${BUILD_WRKSRC}/apps/cwr/Game/PoseidonGame \
		${BUILD_WRKSRC}/apps/cwr/GameDemo/PoseidonGameDemo \
		${BUILD_WRKSRC}/apps/cwr/Server/PoseidonServer \
		${BUILD_WRKSRC}/apps/tools/Studio/PoseidonStudio \
		${BUILD_WRKSRC}/apps/tetris/Tetris/PoseidonTetris \
		${BUILD_WRKSRC}/apps/tools/Tools/PoseidonTools \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/install-cwr-data.sh \
		${STAGEDIR}${PREFIX}/bin/install-cwr-data
	${INSTALL_SCRIPT} ${FILESDIR}/cwr-ce.sh \
		${STAGEDIR}${PREFIX}/bin/cwr-ce

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
BUILD_DEPENDS+=	${LOCALBASE}/include/sse2neon.h:devel/sse2neon
.endif

.include <bsd.port.post.mk>
