PORTNAME=	rpcs3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.28-15339 # git rev-list --count HEAD
DISTVERSIONSUFFIX=	-g4b12c9a9fc
CATEGORIES=	emulators wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PS3 emulator/debugger
WWW=		https://rpcs3.net/

LICENSE=	APACHE20 ISCL GPLv2 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_ISCL=	${WRKSRC_cubeb}/LICENSE
LICENSE_FILE_ZLIB=	${WRKSRC_asmjit}/LICENSE.md

FLAVORS=	qt5 qt6

BUILD_DEPENDS=	flatc:devel/flatbuffers
LIB_DEPENDS=	libxxhash.so:devel/xxhash \
		libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg \
		libpugixml.so:textproc/pugixml

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and SSE2

USE_GITHUB=	yes
GH_ACCOUNT=	RPCS3
GH_TUPLE=	RPCS3:hidapi:hidapi-0.14.0-2-g8b43a97:hidapi/3rdparty/hidapi/hidapi \
		RPCS3:soundtouch:2.3.1-16-g83cfba6:soundtouch/3rdparty/SoundTouch/soundtouch \
		asmjit:asmjit:c598476:asmjit/3rdparty/asmjit/asmjit \
		jbeder:yaml-cpp:yaml-cpp-0.7.0-1-g0b67821:yamlcpp/3rdparty/yaml-cpp/yaml-cpp \
		KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-187-g85a1ed2:spirv_headers/3rdparty/SPIRV/SPIRV-Headers \
		KhronosGroup:SPIRV-Tools:v2022.4:spirv_tools/3rdparty/SPIRV/SPIRV-Tools \
		KhronosGroup:glslang:11.11.0-2-g10423ec6:glslang/3rdparty/glslang/glslang \
		kinetiknz:cubeb:cubeb-0.2-1425-g88585b6:cubeb/3rdparty/cubeb/cubeb \
		miniupnp:miniupnp:miniupnpd_2_3_3:miniupnp/3rdparty/miniupnp/miniupnp \
		wolfSSL:wolfssl:v5.6.3-stable:wolfssl/3rdparty/wolfssl/wolfssl

USES=		cmake elfctl gl iconv:wchar_t llvm:min=16,lib localbase:ldflags \
		openal:soft pkgconfig python:build qt:5 xorg
USE_GL=		gl glew
USE_QT=		qmake:build buildtools:build core concurrent dbus gui multimedia svg widgets
USE_XORG=	x11
CMAKE_ON=	CMAKE_SKIP_RPATH ${CURL FFMPEG FLATBUFFERS LIBPNG PUGIXML XXHASH:L:S/^/USE_SYSTEM_/}
CMAKE_ON+=	BUNDLE_SPEEX # only used by cubeb tests
CMAKE_OFF=	USE_NATIVE_INSTRUCTIONS USE_PRECOMPILED_HEADERS
LDFLAGS+=	-Wl,--as-needed # GLU
ELF_FEATURES=	+wxneeded:bin/${PORTNAME}

.if ${FLAVOR:U} == qt6 || make(makesum) || make(fetch)
PATCH_SITES+=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/:qt6
PATCHFILES+=	2e9c58c38319.patch:-p1:qt6 # https://github.com/RPCS3/rpcs3/pull/12471
PKGNAMESUFFIX=	-${FLAVOR}
USES:=		${USES:S/qt:5/qt:6/}
USE_QT=		base multimedia svg

CONFLICTS_INSTALL=	${PORTNAME}

post-patch:	${FLAVOR}-post-patch
${FLAVOR}-post-patch:
# patch(1) doesn't support renames unlike git-apply(1)
	@${MV}  ${WRKSRC}/rpcs3/rpcs3qt/qt_camera_video_surface.cpp \
		${WRKSRC}/rpcs3/rpcs3qt/qt_camera_video_sink.cpp
	@${MV}  ${WRKSRC}/rpcs3/rpcs3qt/qt_camera_video_surface.h \
		${WRKSRC}/rpcs3/rpcs3qt/qt_camera_video_sink.h
.else
CONFLICTS_INSTALL=	${PORTNAME}-qt6
.endif

OPTIONS_DEFINE=	ALSA EVDEV FAUDIO PULSEAUDIO JACK SDL SNDIO VULKAN
OPTIONS_DEFAULT=EVDEV FAUDIO PULSEAUDIO JACK SDL SNDIO VULKAN

ALSA_BUILD_DEPENDS=	alsa-lib>0:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

EVDEV_DESC=		libevdev-based joystick support
EVDEV_CMAKE_BOOL=	USE_LIBEVDEV
EVDEV_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
EVDEV_LIB_DEPENDS=	libevdev.so:devel/libevdev \
			libudev.so:devel/libudev-devd

FAUDIO_DESC=		FAudio audio support
FAUDIO_LIB_DEPENDS=	libFAudio.so:audio/faudio
FAUDIO_CMAKE_BOOL=	USE_FAUDIO USE_SYSTEM_FAUDIO

JACK_BUILD_DEPENDS=	jackit>0:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

PULSEAUDIO_BUILD_DEPENDS=pulseaudio>0:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CMAKE_BOOL=		USE_SDL USE_SYSTEM_SDL

SNDIO_BUILD_DEPENDS=	sndio>0:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

VULKAN_DESC=		Vulkan renderer
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=	USE_VULKAN

# XXX Unbundle audio/rtmidi
GH_TUPLE+=		thestk:rtmidi:5.0.0:rtmidi/3rdparty/rtmidi/rtmidi
ALSA_LIB_DEPENDS+=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL+= 	RTMIDI_API_ALSA
JACK_LIB_DEPENDS+=	libjack.so:audio/jack
JACK_CMAKE_BOOL+=	RTMIDI_API_JACK

post-patch:
	@${REINPLACE_CMD} -e '/GIT_BRANCH/s/local_build/master/' \
		 -e '/GIT_FULL_BRANCH/s/local_build/${GH_ACCOUNT}\/${GH_PROJECT}\/master/' \
		-e '/GIT_VERSION/s/local_build/${GH_TAGNAME:C/[^-]*-//}/' \
		${WRKSRC}/${PORTNAME}/git-version.cmake

.include <bsd.port.mk>
