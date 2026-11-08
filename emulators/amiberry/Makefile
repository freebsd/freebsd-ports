PORTNAME=	amiberry
DISTVERSIONPREFIX=	v
DISTVERSION=	8.3.0
CATEGORIES=	emulators

MAINTAINER=	polyduekes@proton.me
COMMENT=	Optimized Amiga emulator
WWW=		https://amiberry.com/ \
		https://github.com/BlitterStudio/amiberry

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_GPLv2=	qemu-11.0.1.tar.xz

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	only x86(i386), x86_64(AMD64), Aarch64(ARM64), armv6, \
	armv7, riscv64 and LoongArch64 are supported, see \
	https://github.com/BlitterStudio/amiberry/wiki/Compile-from-source#supported-architectures

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

OPTIONS_DEFINE=	BUNDLE_SDL DBUS DOCS GLES IPC_SOCKET LIBENET \
		LIBMPEG2 LIBSERIALPORT OPENGL PCEM PPC PORTMIDI UAENET_PCAP \
		VULKAN ZSTD WITH_LTO WITH_OPTIMIZE QEMU_PPC
OPTIONS_DEFAULT=	IPC_SOCKET LIBENET LIBMPEG2 LIBSERIALPORT OPENGL \
			PCEM PPC PORTMIDI UAENET_PCAP ZSTD QEMU_PPC
# QEMU requires a 64-bit architecture
OPTIONS_EXCLUDE_armv6= QEMU_PPC
OPTIONS_EXCLUDE_armv7= QEMU_PPC
OPTIONS_EXCLUDE_i386= QEMU_PPC
OPTIONS_EXCLUDE_riscv64=	PCEM
OPTIONS_EXCLUDE_powerpc64=	PCEM
OPTIONS_EXCLUDE_powerpc64le=	PCEM
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
PPC_DESC=		Enable PowerPC accelerator board support
PORTMIDI_DESC=		MIDI emulation via PortMidi
UAENET_PCAP_DESC=	uaenet backend via libpcap
VULKAN_DESC=		Experimental Vulkan renderer
ZSTD_DESC=		CHD compressed disk image support via Zstandard
WITH_LTO_DESC=		Link Time Optimization
WITH_OPTIMIZE_DESC=	Native CPU Optimization
QEMU_PPC_DESC=		Enable QEMU-UAE PowerPC plugin support

VULKAN_PREVENTS=	OPENGL

QEMU_PPC_IMPLIES=	PPC

BUNDLE_SDL_CMAKE_BOOL=	BUNDLE_SDL
DBUS_CMAKE_BOOL=	USE_DBUS
GLES_CMAKE_BOOL=	USE_GLES
IPC_SOCKET_CMAKE_BOOL=	USE_IPC_SOCKET
LIBENET_CMAKE_BOOL=	USE_LIBENET
LIBMPEG2_CMAKE_BOOL=	USE_LIBMPEG2
LIBSERIALPORT_CMAKE_BOOL=	USE_LIBSERIALPORT
OPENGL_CMAKE_BOOL=	USE_OPENGL
PCEM_CMAKE_BOOL=	USE_PCEM
PPC_CMAKE_BOOL=		USE_PPC
PORTMIDI_CMAKE_BOOL=	USE_PORTMIDI
UAENET_PCAP_CMAKE_BOOL=	USE_UAENET_PCAP
VULKAN_CMAKE_BOOL=	USE_VULKAN
ZSTD_CMAKE_BOOL=	USE_ZSTD
WITH_LTO_CMAKE_BOOL=	WITH_LTO
WITH_OPTIMIZE_CMAKE_BOOL=	WITH_OPTIMIZE
QEMU_PPC_CMAKE_BOOL=	USE_QEMU_PPC

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
QEMU_PPC_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qemu.qmp>0:emulators/py-qemu.qmp@${PY_FLAVOR}
QEMU_PPC_LIB_DEPENDS=	libdw.so:devel/elfutils \
			libfdt.so:sysutils/dtc
QEMU_PPC_USES=		inotify
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

QEMU_PPC_MASTER_SITES=	https://download.qemu.org/:qemu
QEMU_PPC_DISTFILES=	qemu-11.0.1.tar.xz:qemu

QEMU_PPC_GH_TUPLE=	BlitterStudio:amiberry-qemu-uae:a12bb101f0d23310431726ca4ff643828e68f7b5:qemu_plugin

QEMU_PPC_USES=	gnome python:build
QEMU_PPC_USE=	gnome=glib20

QEMU_PPC_CMAKE_ON=	-DQEMU_UAE_PLUGIN=${WRKSRC}/qemu-uae.so

pre-build-QEMU_PPC-on:
	@${ECHO_MSG} "Building QEMU-UAE Plugin..."
	(cd ${WRKSRC_qemu_plugin} && ${SETENV} ${MAKE_ENV} \
	QEMU_UAE_NINJA=ninja \
	QEMU_UAE_STRIP_TOOL=strip \
	${SH} ./build-qemu-uae-plugin.sh \
	--tarball ${DISTDIR}/qemu-11.0.1.tar.xz \
	--source-dir ${WRKDIR}/qemu-11.0.1 \
	--output ${WRKSRC}/qemu-uae.so \
	-j ${MAKE_JOBS_NUMBER} \
	-- \
	--enable-fdt=system \
	--extra-cflags="-I${LOCALBASE}/include" \
	--extra-ldflags="-L${LOCALBASE}/lib")

post-extract-QEMU_PPC-on:
	@${CP} ${FILESDIR}/build-qemu-uae-plugin.sh ${WRKSRC_qemu_plugin}/

.include <bsd.port.mk>
