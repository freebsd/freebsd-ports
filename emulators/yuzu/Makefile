PORTNAME=	yuzu
PORTVERSION=	s20210426
PORTREVISION?=	0
CATEGORIES=	emulators

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	b9695ab291f5.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/4836
PATCHFILES+=	abdf90282438.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896
PATCHFILES+=	acf3dae05eae.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896
PATCHFILES+=	0b3842759127.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896
PATCHFILES+=	964339d0ac20.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896
PATCHFILES+=	1602b9e80410.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896
PATCHFILES+=	e32b8885b4a3.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896
PATCHFILES+=	225202534545.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896
PATCHFILES+=	9d1a5e53149b.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896
PATCHFILES+=	2f5a562b8c58.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896
PATCHFILES+=	aa6638d8c01b.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Nintendo Switch emulator/debugger

LICENSE=	APACHE20 BSD3CLAUSE GPLv2+ ISCL LGPL21+ LGPL3+ MIT UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/externals/inih/inih/LICENSE.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/license.txt
LICENSE_FILE_ISCL=	${WRKSRC}/externals/cubeb/LICENSE
LICENSE_FILE_LGPL21+ =	${_LICENSE_STORE}/LGPL21 # soundtouch
LICENSE_FILE_LGPL3+ =	${_LICENSE_STORE}/LGPL3 # sirit
LICENSE_FILE_MIT=	${WRKSRC}/externals/sirit/externals/SPIRV-Headers/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64
ONLY_FOR_ARCHS_REASON=	requires int128

BUILD_DEPENDS=	catch>0:devel/catch \
		nlohmann-json>0:devel/nlohmann-json \
		glslangValidator:graphics/glslang
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd \
		libopus.so:audio/opus \
		libboost_context.so:devel/boost-libs \
		libavcodec.so:multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	yuzu-emu
GH_TAGNAME=	cd80471c9
GH_TUPLE=	yuzu-emu:mbedtls:v2.16.9-52-geac2416b8:mbedtls/externals/mbedtls \
		KhronosGroup:SPIRV-Headers:2c51218:SPIRV_Headers/externals/sirit/externals/SPIRV-Headers \
		KhronosGroup:Vulkan-Headers:v1.2.145:Vulkan_Headers/externals/Vulkan-Headers \
		MerryMage:dynarmic:r4-219-gb2a4da5e:dynarmic/externals/dynarmic \
		ReinUsesLisp:sirit:eefca56:sirit/externals/sirit \
		arsenm:sanitizers-cmake:aab6948:sanitizers_cmake/externals/cubeb/cmake/sanitizers-cmake \
		citra-emu:ext-soundtouch:060181e:soundtouch/externals/soundtouch \
		fmtlib:fmt:7.1.2:fmt/externals/fmt \
		herumi:xbyak:v5.96:xbyak/externals/xbyak \
		nih-at:libzip:rel-1-5-2-93-g89bd6d63:libzip/externals/libzip/libzip \
		kinetiknz:cubeb:cubeb-0.2-1298-g8d53747:cubeb/externals/cubeb \
		benhoyt:inih:r52:inih/externals/inih/inih

USES=		cmake compiler:c++17-lang localbase:ldflags sdl ssl
USE_GCC=	yes:build # libc++ lacks std::atomic_ref, std::ranges
USE_SDL=	sdl2
CMAKE_OFF=	ENABLE_GNUTLS ENABLE_MBEDTLS
LDFLAGS+=	-static-libstdc++ # avoid libc++ conflict, requires files/patch-fmt
LDFLAGS+=	-Wl,--as-needed # Qt5Network
TEST_TARGET=	test

OPTIONS_DEFINE=	ALSA PULSEAUDIO JACK SNDIO VULKAN
OPTIONS_DEFAULT=PULSEAUDIO JACK SNDIO VULKAN
OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

SDL_CMAKE_BOOL=	ENABLE_SDL2
SDL_PLIST_FILES=bin/${PORTNAME}-cmd

QT5_USES=	desktop-file-utils qt:5 shared-mime-info
QT5_USE=	QT=qmake_build,buildtools_build,linguisttools_build,concurrent_build,core,gui,webengine,widgets
QT5_CMAKE_BOOL=	ENABLE_QT ENABLE_QT_TRANSLATION YUZU_USE_QT_WEB_ENGINE
QT5_PLIST_FILES=bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/mime/packages/${PORTNAME}.xml

VULKAN_DESC=		Vulkan renderer
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

.if !exists(${.CURDIR:H:H}/www/qt5-webengine)
# Temporarily disable web applet if qt5-webengine is missing
QT5_USE:=		${QT5_USE:S/,webengine//}
QT5_CMAKE_BOOL:=	${QT5_CMAKE_BOOL:N*WEB_ENGINE}
.endif

post-patch:
	@${REINPLACE_CMD} -e '/check_submodules_present()/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

.include <bsd.port.mk>
