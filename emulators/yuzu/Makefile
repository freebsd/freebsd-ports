# $FreeBSD$

PORTNAME=	yuzu
PORTVERSION=	s20200628
PORTREVISION?=	0
CATEGORIES=	emulators

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	e6085ea35f0b.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/4208
PATCHFILES+=	3b1683a15261.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/4208
PATCHFILES+=	dda90ce1c249.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/4209

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
		gmake:devel/gmake \
		nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzip.so:archivers/libzip \
		libzstd.so:archivers/zstd \
		libopus.so:audio/opus \
		libboost_context.so:devel/boost-libs \
		libfmt.so:devel/libfmt

USE_GITHUB=	yes
GH_ACCOUNT=	yuzu-emu
GH_TAGNAME=	8596a1277
GH_TUPLE=	yuzu-emu:unicorn:1.0.1-153-g73f45735:unicorn/externals/unicorn \
		DarkLordZach:mbedtls:a280e60:mbedtls/externals/mbedtls \
		KhronosGroup:SPIRV-Headers:2c51218:SPIRV_Headers/externals/sirit/externals/SPIRV-Headers \
		KhronosGroup:Vulkan-Headers:v1.2.140:Vulkan_Headers/externals/Vulkan-Headers \
		MerryMage:dynarmic:r3-1-ge7166e8b:dynarmic/externals/dynarmic \
		ReinUsesLisp:sirit:eefca56:sirit/externals/sirit \
		arsenm:sanitizers-cmake:aab6948:sanitizers_cmake/externals/cubeb/cmake/sanitizers-cmake \
		citra-emu:ext-soundtouch:060181e:soundtouch/externals/soundtouch \
		herumi:xbyak:v5.911:xbyak/externals/xbyak \
		kinetiknz:cubeb:cubeb-0.2-1194-g616d773:cubeb/externals/cubeb \
		svn2github:inih:603729d:inih/externals/inih/inih

USES=		cmake compiler:c++17-lang iconv localbase:ldflags \
		python:build sdl ssl
USE_SDL=	sdl2
CXXFLAGS+=	-Wno-narrowing # https://github.com/yuzu-emu/yuzu/issues/3407
LDFLAGS+=	-Wl,--as-needed # Qt5Network
TEST_TARGET=	test

OPTIONS_DEFINE=	ALSA PULSEAUDIO JACK SNDIO VULKAN
OPTIONS_DEFAULT=ALSA PULSEAUDIO JACK SNDIO VULKAN
OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CMAKE_BOOL=	USE_ALSA

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

SDL_CMAKE_BOOL=	ENABLE_SDL2
SDL_PLIST_FILES=bin/${PORTNAME}-cmd \
		bin/${PORTNAME}-tester

QT5_USES=	desktop-file-utils qt:5 shared-mime-info
QT5_USE=	QT=qmake_build,buildtools_build,concurrent_build,core,gui,opengl,webengine,widgets
QT5_CMAKE_BOOL=	ENABLE_QT YUZU_USE_QT_WEB_ENGINE
QT5_PLIST_FILES=bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/mime/packages/${PORTNAME}.xml

VULKAN_DESC=		Vulkan renderer
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

post-patch:
	@${REINPLACE_CMD} -e '/check_submodules_present()/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

.include <bsd.port.mk>
