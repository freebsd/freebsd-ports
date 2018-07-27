# $FreeBSD$

PORTNAME=	rpcs3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.5-678
DISTVERSIONSUFFIX=	-gb0f464d11
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PS3 emulator/debugger

LICENSE=	BSD3CLAUSE BSL GPLv2 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC_cereal}/LICENSE
LICENSE_FILE_BSL=	${WRKSRC_Optional}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC_GSL}/LICENSE
LICENSE_FILE_ZLIB=	${WRKSRC_asmjit}/LICENSE.md

LIB_DEPENDS=	libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and SSE2

USE_GITHUB=	yes
GH_ACCOUNT=	RPCS3
GH_TUPLE=	RPCS3:hidapi:hidapi-0.8.0-rc1-25-gca39ce8:hidapi/3rdparty/hidapi \
		RPCS3:llvm:be9f7bfe2068:llvm/llvm \
		akrzemi1:Optional:f27e790:Optional/3rdparty/Optional \
		Cyan4973:xxHash:v0.6.5:xxHash/3rdparty/xxHash \
		jbeder:yaml-cpp:yaml-cpp-0.6.2-4-g4fb1c4b:yamlcpp/3rdparty/yaml-cpp \
		kobalicek:asmjit:673dcef:asmjit/asmjit \
		KhronosGroup:glslang:5.1-184-gc99304c5:glslang/Vulkan/glslang \
		Microsoft:GSL:fc5fce4:GSL/3rdparty/GSL \
		USCiLab:cereal:v1.2.0:cereal/3rdparty/cereal \
		zeux:pugixml:v1.9:pugixml/3rdparty/pugixml

USES=		cmake:outsource compiler:c++14-lang iconv:wchar_t localbase:ldflags \
		openal:soft pkgconfig qt:5
USE_GL=		gl glew
USE_QT=		qmake_build buildtools_build core dbus gui network widgets qml
USE_XORG=	x11
CMAKE_ON=	CMAKE_SKIP_RPATH USE_SYSTEM_FFMPEG USE_SYSTEM_LIBPNG
CMAKE_OFF=	USE_NATIVE_INSTRUCTIONS
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
CXXFLAGS+=	-Wno-macro-redefined # __STDC_*_MACROS sys/cdefs.h vs. llvm-config
LDFLAGS+=	-Wl,--as-needed # GLU

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
LLVM_CMAKE_BOOL_OFF=	WITHOUT_LLVM

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

VULKAN_DESC=		Vulkan renderer
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-sdk
VULKAN_CMAKE_BOOL=	USE_VULKAN

post-patch:
	@${REINPLACE_CMD} -e '/GIT_BRANCH/s/unknown/master/' \
		-e '/GIT_VERSION/s/unknown/${GH_TAGNAME:C/[^-]*-//}/' \
		${WRKSRC}/${PORTNAME}/git-version.cmake

.include <bsd.port.mk>
