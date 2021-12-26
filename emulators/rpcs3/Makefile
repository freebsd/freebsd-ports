PORTNAME=	rpcs3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.19-13136 # git rev-list --count HEAD
DISTVERSIONSUFFIX=	-g900d7df40
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PS3 emulator/debugger

LICENSE=	APACHE20 ISCL GPLv2 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_ISCL=	${WRKSRC_cubeb}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC_pugixml}/LICENSE.md
LICENSE_FILE_ZLIB=	${WRKSRC_asmjit}/LICENSE.md

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and SSE2

USE_GITHUB=	yes
GH_ACCOUNT=	RPCS3
GH_TUPLE=	RPCS3:hidapi:hidapi-0.8.0-rc1-125-g01f601a:hidapi/3rdparty/hidapi/hidapi \
		RPCS3:llvm-mirror:1c0ca194dc50:llvm/llvm \
		Cyan4973:xxHash:v0.8.1:xxHash/3rdparty/xxHash \
		asmjit:asmjit:723f585:asmjit/3rdparty/asmjit/asmjit \
		google:flatbuffers:v2.0.0:flatbuffers/3rdparty/flatbuffers \
		jbeder:yaml-cpp:yaml-cpp-0.7.0-1-g0b67821:yamlcpp/3rdparty/yaml-cpp/yaml-cpp \
		KhronosGroup:SPIRV-Headers:1.5.3.reservations1:spirv_headers/3rdparty/SPIRV/SPIRV-Headers \
		KhronosGroup:SPIRV-Tools:v2020.4:spirv_tools/3rdparty/SPIRV/SPIRV-Tools \
		KhronosGroup:glslang:11.7.1:glslang/3rdparty/glslang/glslang \
		kinetiknz:cubeb:cubeb-0.2-1345-g773f16b:cubeb/3rdparty/cubeb/cubeb \
		wolfSSL:wolfssl:v4.8.1-stable:wolfssl/3rdparty/wolfssl/wolfssl \
		zeux:pugixml:v1.11.4:pugixml/3rdparty/pugixml

USES=		cmake compiler:c++17-lang gl iconv:wchar_t localbase:ldflags \
		openal:soft pkgconfig python:3.4+,build qt:5 xorg
USE_GL=		gl glew
USE_QT=		qmake_build buildtools_build core concurrent dbus gui multimedia svg widgets
USE_XORG=	x11
CMAKE_ON=	CMAKE_SKIP_RPATH USE_SYSTEM_CURL USE_SYSTEM_FFMPEG USE_SYSTEM_LIBPNG
CMAKE_ON+=	BUNDLE_SPEEX # only used by cubeb tests
CMAKE_OFF=	USE_NATIVE_INSTRUCTIONS USE_PRECOMPILED_HEADERS
LDFLAGS+=	-Wl,--as-needed # GLU

OPTIONS_DEFINE=	ALSA EVDEV FAUDIO PULSEAUDIO JACK SNDIO VULKAN
OPTIONS_DEFAULT=EVDEV FAUDIO PULSEAUDIO JACK SNDIO VULKAN

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

EVDEV_DESC=		libevdev-based joystick support
EVDEV_CMAKE_BOOL=	USE_LIBEVDEV
EVDEV_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
EVDEV_LIB_DEPENDS=	libevdev.so:devel/libevdev

FAUDIO_DESC=		FAudio audio support
FAUDIO_LIB_DEPENDS=	libFAudio.so:audio/faudio
FAUDIO_CMAKE_BOOL=	USE_FAUDIO USE_SYSTEM_FAUDIO

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

VULKAN_DESC=		Vulkan renderer
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=	USE_VULKAN

post-patch:
	@${REINPLACE_CMD} -e '/GIT_BRANCH/s/local_build/master/' \
		 -e '/GIT_FULL_BRANCH/s/local_build/${GH_ACCOUNT}\/${GH_PROJECT}\/master/' \
		-e '/GIT_VERSION/s/local_build/${GH_TAGNAME:C/[^-]*-//}/' \
		${WRKSRC}/${PORTNAME}/git-version.cmake

post-install:
.if exists(/usr/bin/elfctl)
. if 0
	elfctl -e +noaslr ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
. else
# FreeBSD 12.2 lacks https://cgit.freebsd.org/src/commit/?id=f56d7f838f5b
	elfctl -e +aslr ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
. endif
.endif

.include <bsd.port.pre.mk>

# Ignore Mk/bsd.default-versions.mk but respect make.conf(5)
.if !defined(DEFAULT_VERSIONS) || ! ${DEFAULT_VERSIONS:Mllvm*}
LLVM_DEFAULT=	13 # bump if not latest release
.endif
BUILD_DEPENDS+=	clang++${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
USES:=		${USES:Ncompiler*}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}

# XXX Drop after FreeBSD 12.3 EOL
GH_TUPLE+=	llvm:llvm-project:llvmorg-13.0.1-rc1:libcxx
CXXFLAGS+=	-nostdinc++ -isystem${WRKDIR}/libcxx_prefix/include/c++/v1
LDFLAGS+=	-nostdlib++ -L${WRKDIR}/libcxx_prefix/lib -l:libc++.a -lcxxrt

pre-configure:	bundled-libcxx
bundled-libcxx:
	@${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS:M*Ninja*} \
		-DCMAKE_INSTALL_PREFIX:PATH=${WRKDIR}/libcxx_prefix \
		-B ${WRKDIR}/libcxx_build -S ${WRKSRC_libcxx}/libcxx
	@${DO_MAKE_BUILD:NDESTDIR*} install -C ${WRKDIR}/libcxx_build

.include <bsd.port.post.mk>
