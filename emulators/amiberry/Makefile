PORTNAME=	amiberry
DISTVERSIONPREFIX=	v
DISTVERSION=	8.1.5
CATEGORIES=	emulators

MAINTAINER=	polyduekes@proton.me
COMMENT=	Optimized Amiga emulator
WWW=		https://amiberry.com/ \
		https://github.com/BlitterStudio/amiberry

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 riscv64

BUILD_DEPENDS=	${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo \
		${LOCALBASE}/share/cmake/nlohmann_json/nlohmann_jsonConfig.cmake:devel/nlohmann-json
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libFLAC.so:audio/flac \
		libmpg123.so:audio/mpg123 \
		libpng.so:graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES=		iconv cmake desktop-file-utils ninja pkgconfig sdl shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	BlitterStudio
USE_SDL=	sdl3 image3

LDFLAGS+=	-lutil

OPTIONS_DEFINE=	BUNDLE_SDL DBUS DOCS GLES IPC_SOCKET LIBENET \
		LIBMPEG2 LIBSERIALPORT OPENGL PCEM PORTMIDI UAENET_PCAP \
		VULKAN ZSTD WITH_LTO WITH_OPTIMIZE
OPTIONS_DEFAULT=	IPC_SOCKET LIBENET LIBMPEG2 LIBSERIALPORT OPENGL \
			PCEM PORTMIDI UAENET_PCAP ZSTD
OPTIONS_EXCLUDE_risv64=	PCEM
OPTIONS_SUB=	yes

BUNDLE_SDL_DESC=	Bundle SDL3 shared libraries
DBUS_DESC=		DBus control interface
GLES_DESC=		Use OpenGL ES instead of desktop OpenGL
IPC_SOCKET_DESC=	Unix socket IPC control
LIBENET_DESC=		Network emulation via libenet
LIBMPEG2_DESC=		CD32 FMV support via libmpeg2
LIBSERIALPORT_DESC=	Serial port emulation via libserialport
OPENGL_DESC=		OpenGL renderer
PCEM_DESC=		PCem hardware emulation
PORTMIDI_DESC=		MIDI emulation via PortMidi
UAENET_PCAP_DESC=	uaenet backend via libpcap
VULKAN_DESC=		Experimental Vulkan renderer
ZSTD_DESC=		CHD compressed disk image support via Zstandard
WITH_LTO_DESC=		Link Time Optimization
WITH_OPTIMIZE_DESC=	Native CPU Optimization

VULKAN_PREVENTS=	OPENGL

BUNDLE_SDL_CMAKE_BOOL=	BUNDLE_SDL
DBUS_CMAKE_BOOL=	USE_DBUS
GLES_CMAKE_BOOL=	USE_GLES
IPC_SOCKET_CMAKE_BOOL=	USE_IPC_SOCKET
LIBENET_CMAKE_BOOL=	USE_LIBENET
LIBMPEG2_CMAKE_BOOL=	USE_LIBMPEG2
LIBSERIALPORT_CMAKE_BOOL=	USE_LIBSERIALPORT
OPENGL_CMAKE_BOOL=	USE_OPENGL
PCEM_CMAKE_BOOL=	USE_PCEM
PORTMIDI_CMAKE_BOOL=	USE_PORTMIDI
UAENET_PCAP_CMAKE_BOOL=	USE_UAENET_PCAP
VULKAN_CMAKE_BOOL=	USE_VULKAN
ZSTD_CMAKE_BOOL=	USE_ZSTD
WITH_LTO_CMAKE_BOOL=	WITH_LTO
WITH_OPTIMIZE_CMAKE_BOOL=	WITH_OPTIMIZE

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
GLES_LIB_DEPENDS=	libEGL.so:graphics/libglvnd \
			libGLESv2.so:graphics/libglvnd
LIBENET_LIB_DEPENDS=	libenet.so:net/enet
LIBMPEG2_LIB_DEPENDS=	libmpeg2.so:multimedia/libmpeg2
LIBSERIALPORT_LIB_DEPENDS=	libserialport.so:devel/libserialport
OPENGL_LIB_DEPENDS=	libOpenGL.so:graphics/libglvnd
PORTMIDI_LIB_DEPENDS=	libportmidi.so:audio/portmidi
UAENET_PCAP_LIB_DEPENDS=	libpcap.so:net/libpcap
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

.include <bsd.port.mk>
