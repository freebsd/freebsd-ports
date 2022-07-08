PORTNAME=	yuzu
PORTVERSION=	s20220707
CATEGORIES=	emulators
.if make(makesum)
MASTER_SITES=	https://api.yuzu-emu.org/gamedb/?dummy=/:gamedb
.else
MASTER_SITES=	LOCAL/jbeich:gamedb
.endif
DISTFILES=	${PORTNAME}/compatibility_list.json:gamedb
EXTRACT_ONLY=	${DISTFILES:N*\:gamedb:C/\:.*//}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	4a8a248b47a2.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/6598 mainline-merge
PATCHFILES+=	e919bea9c84e.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/7346 mainline-merge
PATCHFILES+=	30e8876ea48a.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/8240 mainline-merge
PATCHFILES+=	d657ea69c94c.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/8240 mainline-merge

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Nintendo Switch emulator/debugger

LICENSE=	APACHE20 BSD3CLAUSE GPLv3+ ISCL MIT UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/externals/inih/inih/LICENSE.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/license.txt
LICENSE_FILE_ISCL=	${WRKSRC}/externals/cubeb/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/externals/sirit/externals/SPIRV-Headers/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and dynarmic backend
BROKEN_aarch64=	https://github.com/yuzu-emu/yuzu/issues/5290
BROKEN_FreeBSD_12=	htonl() in <x86/endian.h> fails -Werror=conversion

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		nlohmann-json>0:devel/nlohmann-json \
		glslangValidator:graphics/glslang
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd \
		libopus.so:audio/opus \
		libavcodec.so:multimedia/ffmpeg
TEST_DEPENDS=	catch>0:devel/catch

USE_GITHUB=	yes
GH_ACCOUNT=	yuzu-emu
GH_TAGNAME=	313f047f9
GH_TUPLE=	yuzu-emu:mbedtls:v2.16.9-115-g8c88150ca:mbedtls/externals/mbedtls \
		KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-32-ga3fdfe8:SPIRV_Headers/externals/sirit/externals/SPIRV-Headers \
		KhronosGroup:Vulkan-Headers:v1.3.213:Vulkan_Headers/externals/Vulkan-Headers \
		MerryMage:dynarmic:6.0.0-4-g7f848707:dynarmic/externals/dynarmic \
		ReinUsesLisp:sirit:aa292d5:sirit/externals/sirit \
		arsenm:sanitizers-cmake:aab6948:sanitizers_cmake/externals/cubeb/cmake/sanitizers-cmake \
		benhoyt:inih:r52:inih/externals/inih/inih \
		fmtlib:fmt:8.1.1:fmt/externals/fmt \
		herumi:xbyak:v5.96:xbyak/externals/xbyak \
		kinetiknz:cubeb:cubeb-0.2-1350-gf79e0cf:cubeb/externals/cubeb \
		yhirose:cpp-httplib:v0.10.8-1-g305a7ab:cpp_httplib/externals/cpp-httplib

USES=		cmake:testing compiler:c++17-lang elfctl localbase:ldflags pkgconfig sdl ssl
USE_GCC=	yes:build # libc++ lacks std::atomic_ref, std::ranges
USE_SDL=	sdl2
CMAKE_ON=	Boost_USE_STATIC_LIBS
CMAKE_ON+=	BUNDLE_SPEEX # only used by cubeb tests
CMAKE_OFF=	YUZU_USE_BUNDLED_OPUS YUZU_USE_EXTERNAL_SDL2 ENABLE_GNUTLS ENABLE_MBEDTLS
CMAKE_OFF+=	${CMAKE_TESTING_ON}
CMAKE_TESTING_ON=	YUZU_TESTS
LDFLAGS+=	-static-libstdc++ # avoid libc++ conflict, requires files/patch-fmt
LDFLAGS+=	-Wl,--as-needed # Qt5Network
ELF_FEATURES=	${PLIST_FILES:Mbin/*:S/^/+wxneeded:/}
PLIST_FILES=	bin/${PORTNAME}-cmd

OPTIONS_DEFINE=	ALSA PULSEAUDIO JACK NLS QT5 SNDIO VAAPI VULKAN WEBENGINE
OPTIONS_DEFAULT=PULSEAUDIO JACK QT5 SNDIO VAAPI VULKAN WEBENGINE

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

NLS_DESC=		UI translations (implies QT5)
NLS_USE=		QT=linguisttools_build
NLS_CMAKE_BOOL=		ENABLE_QT_TRANSLATION
NLS_IMPLIES=		QT5

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

QT5_USES=		desktop-file-utils qt:5 shared-mime-info
QT5_USE=		QT=qmake_build,buildtools_build,concurrent_build,core,gui,widgets
QT5_CMAKE_BOOL=		ENABLE_QT
QT5_PLIST_FILES=	bin/${PORTNAME} \
			share/applications/org.yuzu_emu.yuzu.desktop \
			share/icons/hicolor/scalable/apps/org.yuzu_emu.yuzu.svg \
			share/metainfo/org.yuzu_emu.yuzu.metainfo.xml \
			share/mime/packages/org.yuzu_emu.yuzu.xml

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva

VULKAN_DESC=		Vulkan renderer
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

WEBENGINE_DESC=		Web applet support (implies QT5)
WEBENGINE_USE=		QT=webengine
WEBENGINE_CMAKE_BOOL=	YUZU_USE_QT_WEB_ENGINE
WEBENGINE_IMPLIES=	QT5

post-patch:
	@${REINPLACE_CMD} -e '/check_submodules_present()/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

post-patch-VAAPI-off:
	@${REINPLACE_CMD} -i .nova '/pkg_check.*libva/d' \
		${WRKSRC}/CMakeLists.txt

post-configure:
	@${CP} ${DISTFILES:M*\:gamedb:C/\:.*//:S,^,${_DISTDIR},} \
		${BUILD_WRKSRC}/dist/compatibility_list/

.include <bsd.port.mk>
