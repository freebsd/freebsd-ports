PORTNAME=	xemu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.136
CATEGORIES=	emulators

MAINTAINER=	jakedez7@gmail.com
COMMENT=	Original Xbox emulator based on QEMU
WWW=		https://xemu.app/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>0:textproc/py-tomli@${PY_FLAVOR} \
		bash:shells/bash \
		nlohmann-json>0:devel/nlohmann-json \
		vulkan-headers>0:graphics/vulkan-headers \
		vulkan-loader>0:graphics/vulkan-loader
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libepoxy.so:graphics/libepoxy \
		libpcap.so.1:net/libpcap \
		libsamplerate.so:audio/libsamplerate \
		libslirp.so:net/libslirp \
		libtomlplusplus.so:devel/tomlplusplus \
		libxxhash.so:devel/xxhash
# Loader is dlopened by volk, so it is not a LIB_DEPENDS
RUN_DEPENDS=	vulkan-loader>0:graphics/vulkan-loader

USES=		cmake:indirect compiler:c++17-lang gl gnome inotify \
		localbase:ldflags ninja:build pkgconfig python:build sdl \
		shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	xemu-project
GH_TUPLE=	xemu-project:imgui:b911105fca3ca1b025706dd168e5798070f143a1:imgui/subprojects/imgui \
		xemu-project:implot:8553562dbb2025fd520f4bed57b094767b96c670:implot/subprojects/implot \
		xemu-project:nv2a_vsh_cpu:561fe80da57a881f89000256b459440c0178a7ce:nv2a_vsh_cpu/subprojects/nv2a_vsh_cpu \
		mborgerson:genconfig:42f85f9a2457e61d7e32542c07723565a284fcd6:genconfig/subprojects/genconfig \
		GPUOpen-LibrariesAndSDKs:VulkanMemoryAllocator:1d8f600fd424278486eade7ed3e877c99f0846b1:vma/subprojects/VulkanMemoryAllocator \
		KhronosGroup:SPIRV-Reflect:c90b7b781cdcff63cf1b409ffc7ca0a714e0425e:spirvreflect/subprojects/SPIRV-Reflect \
		KhronosGroup:glslang:275822a6261ee689aadb1da5f09a0ec2f058685c:glslang/subprojects/glslang \
		zeux:volk:3ca312a4f38baa63d8006b6905abbeeb89c8087d:volk/subprojects/volk

# nodefault: GitHub provides the primary distfile
USE_GITLAB=	nodefault
GL_TUPLE=	qemu-project:keycodemapdb:f5772a62ec52591ff6870b7e8ef32482371f22c6:keycodemapdb/subprojects/keycodemapdb \
		qemu-project:berkeley-softfloat-3:b64af41c3276f97f0e181920400ee056b9c88037:softfloat/subprojects/berkeley-softfloat-3 \
		qemu-project:berkeley-testfloat-3:e7af9751d9f9fd3b47911f51a5cfd08af256a9ab:testfloat/subprojects/berkeley-testfloat-3

USE_GL=		gl
USE_GNOME=	glib20
USE_SDL=	sdl3
USE_XORG=	x11

SHEBANG_FILES=	scripts/*.py scripts/*.sh

HAS_CONFIGURE=	yes
# Mirrors what upstream's build.sh passes to QEMU's configure
CONFIGURE_ARGS=	--disable-curl \
		--disable-docs \
		--disable-download \
		--disable-guest-agent \
		--disable-rust \
		--disable-tools \
		--disable-vnc \
		--disable-werror \
		--enable-opengl \
		--enable-sdl \
		--enable-slirp \
		--extra-cflags="-DXBOX=1" \
		--target-list=i386-softmmu

CONFIGURE_OUTSOURCE=	yes

PLIST_FILES=	bin/xemu \
		share/applications/xemu.desktop \
		share/icons/hicolor/scalable/apps/xemu.svg

# Apply the wraps' patch_directory overlays, which meson skips for
# pre-populated subprojects, and stamp the version scripts/xemu-version.sh
# would otherwise take from git.
post-extract:
.for sp in berkeley-softfloat-3 berkeley-testfloat-3
	${CP} -R ${WRKSRC}/subprojects/packagefiles/${sp}/ \
		${WRKSRC}/subprojects/${sp}/
.endfor
	@${ECHO_CMD} ${DISTVERSION} > ${WRKSRC}/XEMU_VERSION
	@${ECHO_CMD} ${GH_TAGNAME} > ${WRKSRC}/XEMU_COMMIT

# QEMU's Makefile wrapper exits 0 without building anything
do-build:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ninja ${_MAKE_JOBS} qemu-system-i386

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/qemu-system-i386 \
		${STAGEDIR}${PREFIX}/bin/xemu
	${INSTALL_DATA} ${WRKSRC}/ui/xemu.desktop \
		${STAGEDIR}${PREFIX}/share/applications/xemu.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/ui/icons/xemu.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/xemu.svg

.include <bsd.port.mk>
