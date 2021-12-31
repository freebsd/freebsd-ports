PORTNAME=	yuzu
PORTVERSION=	s20211231
PORTREVISION?=	0
CATEGORIES=	emulators
MASTER_SITES=	https://api.yuzu-emu.org/gamedb/?dummy=/:gamedb \
		LOCAL/jbeich:gamedb
DISTFILES=	${PORTNAME}/compatibility_list.json:gamedb
EXTRACT_ONLY=	${DISTFILES:N*\:gamedb:C/\:.*//}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	6904f055db88.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6598 mainline-merge
PATCHFILES+=	e919bea9c84e.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/7346 mainline-merge
PATCHFILES+=	16e5fc080281.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/7497 mainline-merge
PATCHFILES+=	57909b727b2e.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/7497 mainline-merge

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

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and dynarmic backend
BROKEN_aarch64=	https://github.com/yuzu-emu/yuzu/issues/5290

BUILD_DEPENDS=	catch>0:devel/catch \
		boost-libs>0:devel/boost-libs \
		nlohmann-json>0:devel/nlohmann-json \
		glslangValidator:graphics/glslang
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd \
		libopus.so:audio/opus \
		libavcodec.so:multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	yuzu-emu
GH_TAGNAME=	eb7d36165
GH_TUPLE=	yuzu-emu:mbedtls:v2.16.9-115-g8c88150ca:mbedtls/externals/mbedtls \
		KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-32-ga3fdfe8:SPIRV_Headers/externals/sirit/externals/SPIRV-Headers \
		KhronosGroup:Vulkan-Headers:v1.2.202:Vulkan_Headers/externals/Vulkan-Headers \
		MerryMage:dynarmic:r5-129-g28714ee7:dynarmic/externals/dynarmic \
		ReinUsesLisp:sirit:a395963:sirit/externals/sirit \
		arsenm:sanitizers-cmake:aab6948:sanitizers_cmake/externals/cubeb/cmake/sanitizers-cmake \
		benhoyt:inih:r52:inih/externals/inih/inih \
		citra-emu:ext-soundtouch:060181e:soundtouch/externals/soundtouch \
		fmtlib:fmt:8.0.0:fmt/externals/fmt \
		herumi:xbyak:v5.96:xbyak/externals/xbyak \
		kinetiknz:cubeb:cubeb-0.2-1345-g773f16b:cubeb/externals/cubeb \
		yhirose:cpp-httplib:v0.9.0-5-g9648f95:cpp_httplib/externals/cpp-httplib

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pkgconfig sdl ssl
USE_GCC=	yes:build # libc++ lacks std::atomic_ref, std::ranges
USE_SDL=	sdl2
CMAKE_ON=	Boost_USE_STATIC_LIBS
CMAKE_ON+=	BUNDLE_SPEEX # only used by cubeb tests
CMAKE_OFF=	YUZU_USE_EXTERNAL_SDL2 ENABLE_GNUTLS ENABLE_MBEDTLS
LDFLAGS+=	-static-libstdc++ # avoid libc++ conflict, requires files/patch-fmt
LDFLAGS+=	-Wl,--as-needed # Qt5Network

OPTIONS_DEFINE=	ALSA PULSEAUDIO JACK SNDIO VAAPI VULKAN
OPTIONS_DEFAULT=PULSEAUDIO JACK SNDIO VAAPI VULKAN
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

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva

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

post-configure:
	@${CP} ${DISTFILES:M*\:gamedb:C/\:.*//:S,^,${_DISTDIR},} \
		${BUILD_WRKSRC}/dist/compatibility_list/

post-patch-VAAPI-off:
	@${REINPLACE_CMD} -i .nova '/pkg_check.*libva/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
