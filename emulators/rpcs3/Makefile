# $FreeBSD$

PORTNAME=	rpcs3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.15-11937 # git rev-list --count HEAD
DISTVERSIONSUFFIX=	-ge3a7fdddd
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PS3 emulator/debugger

LICENSE=	APACHE20 BSD3CLAUSE BSL GPLv2 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC_cereal}/LICENSE
LICENSE_FILE_BSL=	${WRKSRC_span}/LICENSE_1_0.txt
LICENSE_FILE_MIT=	${WRKSRC_pugixml}/LICENSE.md
LICENSE_FILE_ZLIB=	${WRKSRC_asmjit}/LICENSE.md

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and SSE2

USE_GITHUB=	yes
GH_ACCOUNT=	RPCS3
GH_TUPLE=	RPCS3:hidapi:hidapi-0.8.0-rc1-28-g8961cf8:hidapi/3rdparty/hidapi \
		RPCS3:llvm-mirror:716bb292ba3:llvm/llvm \
		Cyan4973:xxHash:v0.8.0:xxHash/3rdparty/xxHash \
		FNA-XNA:FAudio:20.05:FAudio/3rdparty/FAudio \
		google:flatbuffers:v1.11.0:flatbuffers/3rdparty/flatbuffers \
		jbeder:yaml-cpp:yaml-cpp-0.6.3-30-g6a211f0:yamlcpp/3rdparty/yaml-cpp \
		kobalicek:asmjit:723f585:asmjit/asmjit \
		KhronosGroup:SPIRV-Headers:1.5.3.reservations1:spirv_headers/Vulkan/spirv-headers \
		KhronosGroup:SPIRV-Tools:v2020.4:spirv_tools/Vulkan/spirv-tools \
		KhronosGroup:glslang:8.13.3743-225-g517f39ee:glslang/Vulkan/glslang \
		tcbrindle:span:9d7559a:span/3rdparty/span \
		USCiLab:cereal:v1.3.0-5-g60c69df9:cereal/3rdparty/cereal \
		wolfSSL:wolfssl:v4.5.0-stable-80-g39b544860:wolfssl/3rdparty/wolfssl \
		zeux:pugixml:v1.9-51-g8bf806c:pugixml/3rdparty/pugixml

USES=		cmake compiler:c++17-lang gl iconv:wchar_t localbase:ldflags \
		openal:soft pkgconfig python:3.4+,build qt:5 xorg
USE_GL=		gl glew
USE_QT=		qmake_build buildtools_build core concurrent dbus gui widgets
USE_XORG=	x11
CMAKE_ON=	CMAKE_SKIP_RPATH USE_SYSTEM_CURL USE_SYSTEM_FFMPEG USE_SYSTEM_LIBPNG
CMAKE_OFF=	USE_NATIVE_INSTRUCTIONS USE_PRECOMPILED_HEADERS
LDFLAGS+=	-Wl,--as-needed # GLU

OPTIONS_DEFINE=	ALSA EVDEV FAUDIO PULSEAUDIO VULKAN
OPTIONS_DEFAULT=EVDEV FAUDIO VULKAN

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CMAKE_BOOL=	USE_ALSA

EVDEV_DESC=		libevdev-based joystick support
EVDEV_CMAKE_BOOL=	USE_LIBEVDEV
EVDEV_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
EVDEV_LIB_DEPENDS=	libevdev.so:devel/libevdev

FAUDIO_DESC=		FAudio audio support
FAUDIO_USES=		sdl
FAUDIO_USE=		SDL=sdl2
FAUDIO_CMAKE_BOOL=	USE_FAUDIO

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

VULKAN_DESC=		Vulkan renderer
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=	USE_VULKAN

post-patch:
	@${REINPLACE_CMD} -e '/GIT_BRANCH/s/local_build/master/' \
		 -e '/GIT_FULL_BRANCH/s/local_build/${GH_ACCOUNT}\/${GH_PROJECT}\/master/' \
		-e '/GIT_VERSION/s/local_build/${GH_TAGNAME:C/[^-]*-//}/' \
		${WRKSRC}/${PORTNAME}/git-version.cmake

.include <bsd.port.pre.mk>

# Ignore Mk/bsd.default-versions.mk but respect make.conf(5)
.if !defined(DEFAULT_VERSIONS) || ! ${DEFAULT_VERSIONS:Mllvm*}
LLVM_DEFAULT=	11 # bump if not latest release
.endif
BUILD_DEPENDS+=	clang++${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
USES:=		${USES:Ncompiler*}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}

.include <bsd.port.post.mk>
