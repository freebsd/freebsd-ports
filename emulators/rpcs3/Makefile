# $FreeBSD$

PORTNAME=	rpcs3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.6-7816 # git rev-list --count HEAD
DISTVERSIONSUFFIX=	-gde5379a69
PORTREVISION=	1
CATEGORIES=	emulators

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	1e28a22860c0.patch:-p1
PATCHFILES+=	ff31ccc1eddf.patch:-p1 # version

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PS3 emulator/debugger

LICENSE=	BSD3CLAUSE BSL GPLv2 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC_cereal}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC_GSL}/LICENSE
LICENSE_FILE_ZLIB=	${WRKSRC_asmjit}/LICENSE.md

LIB_DEPENDS=	libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and SSE2

USE_GITHUB=	yes
GH_ACCOUNT=	RPCS3
GH_TUPLE=	RPCS3:hidapi:hidapi-0.8.0-rc1-27-g9220f5e:hidapi/3rdparty/hidapi \
		RPCS3:llvm:5c906fd1694e:llvm/llvm \
		Cyan4973:xxHash:v0.6.5:xxHash/3rdparty/xxHash \
		jbeder:yaml-cpp:yaml-cpp-0.6.2-8-gc90c08c:yamlcpp/3rdparty/yaml-cpp \
		kobalicek:asmjit:673dcef:asmjit/asmjit \
		KhronosGroup:glslang:5.1-184-gc99304c5:glslang/Vulkan/glslang \
		Microsoft:GSL:v2.0.0:GSL/3rdparty/GSL \
		USCiLab:cereal:v1.2.0:cereal/3rdparty/cereal \
		zeux:pugixml:v1.9:pugixml/3rdparty/pugixml

USES=		cmake compiler:c++17-lang iconv:wchar_t localbase:ldflags \
		openal:soft pkgconfig qt:5
USE_GL=		gl glew
USE_QT=		qmake_build buildtools_build core dbus declarative gui network widgets
USE_XORG=	x11
LLD_UNSAFE=	yes # XXX ports/219089
CMAKE_ON=	CMAKE_SKIP_RPATH USE_SYSTEM_FFMPEG USE_SYSTEM_LIBPNG
CMAKE_OFF=	USE_NATIVE_INSTRUCTIONS
CXXFLAGS+=	-Wno-macro-redefined # __STDC_*_MACROS sys/cdefs.h vs. llvm-config
LDFLAGS+=	-Wl,--as-needed # GLU

OPTIONS_DEFINE=	ALSA EVDEV GDB LLVM PULSEAUDIO VULKAN
OPTIONS_DEFAULT=ALSA LLVM VULKAN

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
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=	USE_VULKAN

post-patch:
	@${REINPLACE_CMD} -e '/GIT_BRANCH/s/unknown/master/' \
		-e '/GIT_TAG/s/unknown/${GH_TAGNAME:C/-.*//}/' \
		-e '/GIT_VERSION/s/unknown/${GH_TAGNAME:C/[^-]*-//}/' \
		${WRKSRC}/${PORTNAME}/git-version.cmake

.include <bsd.port.mk>
