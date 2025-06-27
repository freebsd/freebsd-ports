PORTNAME=	yuzu
PORTVERSION=	s20240301
PORTREVISION=	8
CATEGORIES=	emulators wayland
.if make(makesum)
MASTER_SITES=	https://api.yuzu-emu.org/gamedb/?dummy=/:gamedb
.else
MASTER_SITES=	LOCAL/jbeich:gamedb
.endif
MASTER_SITES+=	https://codeberg.org/TxzK/${PORTNAME}/archive/${GH_TAGNAME}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${PORTNAME}-s20230424/compatibility_list.json:gamedb
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTFILES:N*\:gamedb:C/\:.*//}

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
# XXX Need Ryujinx or a Yuzu fork that regularly improves game compatibility
DEPRECATED=	Project discontinued

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		nlohmann-json>0:devel/nlohmann-json \
		simpleini>0:devel/simpleini \
		glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers \
		vulkan-utility-libraries>0:graphics/vulkan-utility-libraries
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd \
		libopus.so:audio/opus \
		libfmt.so:devel/libfmt \
		libavcodec.so:multimedia/ffmpeg \
		libenet.so:net/enet
TEST_DEPENDS=	catch2>0:devel/catch2

FLAVORS=	qt6 qt5
qt5_PKGNAMESUFFIX=	-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}
qt5_OPTIONS_SLAVE=	QT5
qt5_OPTIONS_EXCLUDE=	QT6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-qt5

USE_GITHUB=	nodefault
GH_ACCOUNT=	yuzu-mirror
GH_TAGNAME=	15e6e48bef
GH_TUPLE=	yuzu-mirror:mbedtls:v2.16.9-115-g8c88150ca:mbedtls/externals/mbedtls \
		yuzu-mirror:sirit:ab75463:sirit/externals/sirit \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:v3.0.1-114-g2f382df:VulkanMemoryAllocator/externals/VulkanMemoryAllocator \
		KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-201-gc214f6f:SPIRV_Headers/externals/sirit/externals/SPIRV-Headers \
		yuzu-mirror:dynarmic:6.6.2-15-gba8192d8:dynarmic/externals/dynarmic \
		merryhime:oaknut:2.0.1:oaknut/externals/oaknut \
		arun11299:cpp-jwt:v1.4-18-g10ef573:cpp_jwt/externals/cpp-jwt \
		arsenm:sanitizers-cmake:aab6948:sanitizers_cmake/externals/cubeb/cmake/sanitizers-cmake \
		eggert:tz:2022g-11-g16ce126a:tz/externals/nx_tzdb/tzdb_to_nx/externals/tz/tz \
		herumi:xbyak:v6.68:xbyak/externals/xbyak \
		kinetiknz:cubeb:cubeb-0.2-1452-g48689ae:cubeb/externals/cubeb \
		lat9nq:tzdb_to_nx:221202-15-g9792969:tzdb_to_nx/externals/nx_tzdb/tzdb_to_nx \
		yhirose:cpp-httplib:v0.14.1:cpp_httplib/externals/cpp-httplib

USES=		cmake:testing localbase:ldflags pkgconfig sdl ssl
USE_SDL=	sdl2
WRKSRC=		${WRKDIR}/${PORTNAME}
CMAKE_ON=	Boost_USE_STATIC_LIBS
CMAKE_ON+=	BUNDLE_SPEEX # only used by cubeb tests
CMAKE_ON+=	CMAKE_DISABLE_FIND_PACKAGE_LLVM # only need Demangle but llvm* is huge
CMAKE_OFF=	YUZU_CHECK_SUBMODULES YUZU_USE_EXTERNAL_SDL2
CMAKE_OFF+=	YUZU_USE_EXTERNAL_VULKAN_HEADERS YUZU_USE_EXTERNAL_VULKAN_UTILITY_LIBRARIES
CMAKE_OFF+=	HTTPLIB_USE_BROTLI_IF_AVAILABLE # unused by ENABLE_WEB_SERVICE
CMAKE_OFF+=	${ARCH:Maarch64:C/.+/YUZU_USE_PRECOMPILED_HEADERS DYNARMIC_USE_PRECOMPILED_HEADERS/}
CMAKE_OFF+=	${CMAKE_TESTING_ON}
CMAKE_TESTING_ON=	YUZU_TESTS
LDFLAGS+=	-Wl,--as-needed # Qt5Network
PLIST_FILES=	bin/${PORTNAME}-cmd \
		bin/${PORTNAME}-room

OPTIONS_DEFINE=	ALSA GUI PULSEAUDIO JACK LTO NLS SNDIO VAAPI VULKAN WEBENGINE
OPTIONS_DEFAULT=PULSEAUDIO JACK LTO QT6 SNDIO VAAPI VULKAN WEBENGINE
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	QT5 QT6
OPTIONS_SLAVE=		${${FLAVOR}_OPTIONS_SLAVE}
OPTIONS_EXCLUDE=	${${FLAVOR}_OPTIONS_EXCLUDE}

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

GUI_USES=		desktop-file-utils shared-mime-info
GUI_CMAKE_BOOL=		ENABLE_QT
GUI_PLIST_FILES=	bin/${PORTNAME} \
			share/applications/org.yuzu_emu.yuzu.desktop \
			share/icons/hicolor/scalable/apps/org.yuzu_emu.yuzu.svg \
			share/metainfo/org.yuzu_emu.yuzu.metainfo.xml \
			share/mime/packages/org.yuzu_emu.yuzu.xml

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

LTO_CMAKE_BOOL=		YUZU_ENABLE_LTO

NLS_DESC=		UI translations (implies ${NLS_IMPLIES})
NLS_USE=		QT=${"${PORT_OPTIONS:MQT5}":?linguist:}tools:build
NLS_CMAKE_BOOL=		ENABLE_QT_TRANSLATION
NLS_IMPLIES=		GUI

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

QT5_USES=		qt:5
QT5_USE=		QT=qmake:build,buildtools:build,concurrent:build,core,dbus,gui,multimedia,widgets
QT5_IMPLIES=		GUI

QT6_USES=		qt:6
QT6_USE=		QT=base
QT6_CMAKE_BOOL=		ENABLE_QT6
QT6_IMPLIES=		GUI

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva

VULKAN_DESC=		Vulkan renderer
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

WEBENGINE_DESC=		Web applet support (implies ${WEBENGINE_IMPLIES})
WEBENGINE_USE=		QT=webengine
WEBENGINE_CMAKE_BOOL=	YUZU_USE_QT_WEB_ENGINE
WEBENGINE_IMPLIES=	GUI

post-extract:
	@${CP} ${DISTFILES:M*\:gamedb:C/\:.*//:S,^,${_DISTDIR},} \
		${WRKSRC}/dist/compatibility_list/

post-patch:
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in
# https://github.com/ConsoleKit2/ConsoleKit2/issues/150
	@${REINPLACE_CMD} -e 's,/login1,/ConsoleKit/Manager,' \
		-e 's,login1,ConsoleKit,' \
		${WRKSRC}/src/${PORTNAME}/main.cpp
.ifdef DEPRECATED
	@${GREP} -Flr 'yuzu-emu' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's,${WWW:S,/$,,},https://web.archive.org/web/20240304190805/&,g' \
		-e 's,https://api.yuzu-emu.org,,g' \
		-e 's,https://profile.yuzu-emu.org/,,g' \
		-e 's,\(https://github.com\)/\(yuzu-emu\),\1/${GH_ACCOUNT},g'
.endif

post-patch-VAAPI-off:
	@${REINPLACE_CMD} -i .nova '/pkg_check.*libva/d' \
		${WRKSRC}/CMakeLists.txt

post-install:
.if exists(/usr/bin/elfctl)
	${ELFCTL} -e +wxneeded ${STAGEDIR}${PREFIX}/bin/*
.endif

.include <bsd.port.mk>
