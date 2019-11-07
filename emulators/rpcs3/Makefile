# $FreeBSD$

PORTNAME=	rpcs3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.7-9082 # git rev-list --count HEAD
DISTVERSIONSUFFIX=	-g77ac875b0
CATEGORIES=	emulators

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
		RPCS3:llvm:9836c299733e:llvm/llvm \
		Cyan4973:xxHash:v0.6.5:xxHash/3rdparty/xxHash \
		FNA-XNA:FAudio:19.11:FAudio/3rdparty/FAudio \
		jbeder:yaml-cpp:yaml-cpp-0.6.2-23-geca9cfd:yamlcpp/3rdparty/yaml-cpp \
		kobalicek:asmjit:fc251c9:asmjit/asmjit \
		KhronosGroup:glslang:7.11.3214:glslang/Vulkan/glslang \
		Microsoft:GSL:v2.0.0:GSL/3rdparty/GSL \
		USCiLab:cereal:v1.2.0:cereal/3rdparty/cereal \
		zeux:pugixml:v1.9-51-g8bf806c:pugixml/3rdparty/pugixml

USES=		cmake compiler:c++17-lang gl iconv:wchar_t localbase:ldflags \
		openal:soft pkgconfig qt:5 xorg
USE_GL=		gl glew
USE_QT=		qmake_build buildtools_build core concurrent dbus declarative gui network widgets
USE_XORG=	x11
CMAKE_ON=	CMAKE_SKIP_RPATH USE_SYSTEM_FFMPEG USE_SYSTEM_LIBPNG
CMAKE_OFF=	USE_NATIVE_INSTRUCTIONS
LDFLAGS+=	-Wl,--as-needed # GLU

# XXX Drop after FreeBSD 12.0 EOL
.if exists(/usr/lib/clang/6.0.1)
LLD_UNSAFE=	yes # XXX ports/219089
.endif

# XXX Remove after FreeBSD 11.2/12.0 reach EOL i.e., around 2020-02-01
.if make(makesum) || (!exists(/usr/include/c++/v1/charconv) && exists(/usr/lib/libc++.so))
MASTER_SITES+=	https://releases.llvm.org/${LLVM_VER}/:libcxx
DISTFILES+=	libcxx-${LLVM_VER}.src.tar.xz:libcxx
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-no-cotire
CXXFLAGS+=	-nostdinc++ -isystem${WRKDIR}/libcxx-${LLVM_VER}.src/include
LLVM_VER=	8.0.0 # same as FreeBSD 11.3
.endif

OPTIONS_DEFINE=	ALSA EVDEV FAUDIO LLVM PULSEAUDIO VULKAN
OPTIONS_DEFAULT=FAUDIO LLVM VULKAN

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CMAKE_BOOL=	USE_ALSA

EVDEV_DESC=		libevdev-based joystick support
EVDEV_CMAKE_BOOL=	USE_LIBEVDEV
EVDEV_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
EVDEV_LIB_DEPENDS=	libevdev.so:devel/libevdev

FAUDIO_DESC=		FAudio audio support
FAUDIO_LIB_DEPENDS=	libFAudio.so:audio/faudio
FAUDIO_CMAKE_BOOL=	USE_FAUDIO

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
