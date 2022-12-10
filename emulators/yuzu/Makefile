PORTNAME=	yuzu
PORTVERSION=	s20221206
CATEGORIES=	emulators
.if make(makesum)
MASTER_SITES=	https://api.yuzu-emu.org/gamedb/?dummy=/:gamedb
.else
MASTER_SITES=	LOCAL/jbeich:gamedb
.endif
DISTFILES=	${PORTNAME}-${DISTVERSIONFULL}/compatibility_list.json:gamedb
EXTRACT_ONLY=	${DISTFILES:N*\:gamedb:C/\:.*//}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	c17d71240b23.patch:-p1 # https://github.com/yuzu-emu/yuzu/pull/9042 mainline-merge

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Nintendo Switch emulator/debugger
WWW=		https://yuzu-emu.org/

LICENSE=	APACHE20 BSD3CLAUSE GPLv3+ ISCL MIT UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/externals/sirit/LICENSE.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE.txt
LICENSE_FILE_ISCL=	${WRKSRC}/externals/cubeb/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/externals/sirit/externals/SPIRV-Headers/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and dynarmic backend
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
GH_TAGNAME=	bfdd51278
GH_TUPLE=	yuzu-emu:mbedtls:v2.16.9-115-g8c88150ca:mbedtls/externals/mbedtls \
		yuzu-emu:sirit:d7ad93a:sirit/externals/sirit \
		KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-201-gc214f6f:SPIRV_Headers/externals/sirit/externals/SPIRV-Headers \
		KhronosGroup:Vulkan-Headers:v1.3.236:Vulkan_Headers/externals/Vulkan-Headers \
		MerryMage:dynarmic:6.4.0:dynarmic/externals/dynarmic \
		arun11299:cpp-jwt:v1.4-14-ge12ef06:cpp_jwt/externals/cpp-jwt \
		arsenm:sanitizers-cmake:aab6948:sanitizers_cmake/externals/cubeb/cmake/sanitizers-cmake \
		benhoyt:inih:r52:inih/externals/inih/inih \
		herumi:xbyak:v6.64:xbyak/externals/xbyak \
		kinetiknz:cubeb:cubeb-0.2-1350-gf79e0cf:cubeb/externals/cubeb \
		lsalzman:enet:v1.3.13-14-g39a72ab:enet/externals/enet \
		yhirose:cpp-httplib:v0.10.8-1-g305a7ab:cpp_httplib/externals/cpp-httplib

USES=		cmake:testing compiler:c++17-lang elfctl localbase:ldflags pkgconfig sdl ssl
USE_GCC=	yes:build # libc++ lacks std::atomic_ref, std::ranges
USE_SDL=	sdl2
CMAKE_ON=	Boost_USE_STATIC_LIBS
CMAKE_ON+=	BUNDLE_SPEEX # only used by cubeb tests
CMAKE_OFF=	YUZU_CHECK_SUBMODULES YUZU_USE_BUNDLED_OPUS YUZU_USE_EXTERNAL_SDL2
CMAKE_OFF+=	YUZU_USE_PRECOMPILED_HEADERS DYNARMIC_USE_PRECOMPILED_HEADERS # GCC
CMAKE_OFF+=	${CMAKE_TESTING_ON}
CMAKE_TESTING_ON=	YUZU_TESTS
LDFLAGS+=	-static-libstdc++ -static-libgcc # avoid libc++ conflict, requires files/patch-fmt
LDFLAGS+=	-Wl,--as-needed # Qt5Network
ELF_FEATURES=	${PLIST_FILES:Mbin/*:S/^/+wxneeded:/}
PLIST_FILES=	bin/${PORTNAME}-cmd \
		bin/${PORTNAME}-room

OPTIONS_DEFINE=	ALSA PULSEAUDIO JACK NLS QT5 SNDIO VAAPI VULKAN WEBENGINE
OPTIONS_DEFAULT=PULSEAUDIO JACK QT5 SNDIO VAAPI VULKAN WEBENGINE

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

NLS_DESC=		UI translations (implies QT5)
NLS_USE=		QT=linguisttools:build
NLS_CMAKE_BOOL=		ENABLE_QT_TRANSLATION
NLS_IMPLIES=		QT5

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

QT5_USES=		desktop-file-utils qt:5 shared-mime-info
QT5_USE=		QT=qmake:build,buildtools:build,concurrent:build,core,dbus,gui,multimedia,widgets
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

post-extract:
	@${CP} ${DISTFILES:M*\:gamedb:C/\:.*//:S,^,${_DISTDIR},} \
		${WRKSRC}/dist/compatibility_list/

post-patch:
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in
# Temporarily use ConsoleKit2 like sysutils/gnome-settings-daemon
	@${REINPLACE_CMD} -e 's,/login1,/ConsoleKit/Manager,' \
		-e 's,login1,ConsoleKit,' \
		${WRKSRC}/src/${PORTNAME}/main.cpp

post-patch-VAAPI-off:
	@${REINPLACE_CMD} -i .nova '/pkg_check.*libva/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
