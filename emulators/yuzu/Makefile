PORTNAME=	yuzu
PORTVERSION=	s20210513
PORTREVISION?=	0
CATEGORIES=	emulators

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a2686843592e.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/4836 mainline-merge
PATCHFILES+=	e2d5cff34554.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	5e559324a080.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	3bfdd34ce241.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	234d7ded1c52.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	2caf2f0fe288.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	b9ff77485840.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	26907dfe941c.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	043027f85b64.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	169384b954b9.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	16a67d43d9a4.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/5896 mainline-merge
PATCHFILES+=	d08bd3e062e6.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	ed25191ee634.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	7a06037c5fd2.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	75f23ad494cc.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	9f44a44f2f6d.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	cfed6936f3c0.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	44c763f9c630.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	c6de9657be71.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	f54ea749a4a5.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	934b2d8842f0.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	41928dfdda96.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	da25a5986666.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	21671d05a362.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	49c4c329f6c8.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	913971417e07.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	2c1e119c4a57.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	343d92a09276.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	b9f543b29f2d.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	f2c26443f85a.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	fc086f93b216.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	12d569e48383.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge
PATCHFILES+=	eee302b9b9fe.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6299 mainline-merge

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
GH_TAGNAME=	904584e4b
GH_TUPLE=	yuzu-emu:mbedtls:v2.16.9-115-g8c88150ca:mbedtls/externals/mbedtls \
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

USES=		cmake:testing compiler:c++17-lang localbase:ldflags sdl ssl
USE_GCC=	yes:build # libc++ lacks std::atomic_ref, std::ranges
USE_SDL=	sdl2
CMAKE_OFF=	ENABLE_GNUTLS ENABLE_MBEDTLS
LDFLAGS+=	-static-libstdc++ # avoid libc++ conflict, requires files/patch-fmt
LDFLAGS+=	-Wl,--as-needed # Qt5Network

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
