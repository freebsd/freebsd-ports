# $FreeBSD$

PORTNAME=	rpcs3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.3-388
DISTVERSIONSUFFIX=	-g9650218b
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PS3 emulator/debugger

LICENSE=	BSD3CLAUSE BSL GPLv2 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/3rdparty/cereal/LICENSE
LICENSE_FILE_BSL=	${WRKSRC}/Utilities/LICENSE_1_0.txt
LICENSE_FILE_MIT=	${WRKSRC}/3rdparty/GSL/LICENSE
LICENSE_FILE_ZLIB=	${WRKSRC}/asmjit/LICENSE.md

LIB_DEPENDS=	libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and SSSE3

USE_GITHUB=	yes
GH_ACCOUNT=	RPCS3
GH_TUPLE=	RPCS3:hidapi:hidapi-0.8.0-rc1-25-gca39ce8:hidapi/3rdparty/hidapi \
		RPCS3:pugixml:f205aaf:pugixml/3rdparty/pugixml \
		RPCS3:yaml-cpp:release-0.5.3-62-g017626a:yamlcpp/Utilities/yaml-cpp \
		kobalicek:asmjit:1370fe6:asmjit/asmjit \
		Microsoft:GSL:fc5fce4:GSL/3rdparty/GSL \
		USCiLab:cereal:v1.2.0:cereal/3rdparty/cereal

USES=		cmake compiler:c++14-lang iconv:wchar_t localbase:ldflags \
		openal:soft pkgconfig
USE_GL=		gl glew
USE_QT5=	qmake_build buildtools_build core dbus gui widgets
USE_XORG=	x11
EXTRA_PATCHES+=	${EXTRA_PATCHES_${OPSYS}_${OSREL}}
EXTRA_PATCHES_FreeBSD_10.3=	${PATCHDIR}/extra-patch-no-thread_local
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH=on -DUSE_SYSTEM_LIBPNG=on -DUSE_SYSTEM_FFMPEG=on
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
CXXFLAGS+=	-Wno-macro-redefined # __STDC_*_MACROS sys/cdefs.h vs. llvm-config
LDFLAGS+=	-Wl,--as-needed # GLU
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \

OPTIONS_DEFINE=	ALSA EVDEV GDB LLVM PULSEAUDIO VULKAN
OPTIONS_DEFAULT=ALSA LLVM VULKAN
.if !exists(${.CURDIR:H:H}/graphics/vulkan-sdk)
OPTIONS_EXCLUDE=VULKAN # XXX ports/222175
.endif

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CMAKE_BOOL=	USE_ALSA

EVDEV_DESC=		libevdev-based joystick support
EVDEV_CMAKE_BOOL=	USE_LIBEVDEV
EVDEV_LIB_DEPENDS=	libevdev.so:devel/libevdev

GDB_DESC=		GDB remote stub (powerpc64 target)
GDB_CMAKE_BOOL=		WITH_GDB

LLVM_DESC=		LLVM-based PPU recompiler
LLVM_BUILD_DEPENDS=	llvm40>0:devel/llvm40
LLVM_CMAKE_BOOL_OFF=	WITHOUT_LLVM

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

VULKAN_DESC=		Vulkan renderer
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/lib/libglslang.a:devel/glslang
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-sdk
VULKAN_CMAKE_BOOL=	USE_VULKAN VULKAN_PREBUILT

post-patch:
	@${REINPLACE_CMD} -e '/GIT_BRANCH/s/unknown/master/' \
		-e '/GIT_VERSION/s/unknown/${GH_TAGNAME:C/[^-]*-//}/' \
		${WRKSRC}/${PORTNAME}/git-version.cmake

.include <bsd.port.mk>
