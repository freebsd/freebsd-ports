PORTNAME=	mesa
DISTVERSION=	23.3-branchpoint-2692
DISTVERSIONSUFFIX=	-ge46e9ee46c7
CATEGORIES=	graphics
PKGNAMESUFFIX=	-devel

PATCH_SITES=	https://github.com/mesa3d/${GL_PROJECT}/commit/:github
PATCHFILES+=	700efacda59c.patch:-p1:github
PATCH_SITES+=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	58b505331612.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/6881
PATCHFILES+=	2930dcbb3329.patch:-p1 # https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/22246

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Bleeding edge Mesa drivers (OpenCL, OpenGL, Vulkan)
WWW=		https://www.mesa3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.rst

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	Limited scope: no old drivers and no software rendering. \
			See also https://mesamatrix.net/

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libOpenGL.so:graphics/libglvnd \
		libexpat.so:textproc/expat2
.if !exists(/usr/lib/libelf.so)
# DragonFly doesn't install it yet
LIB_DEPENDS+=	libelf.so:devel/libelf
.endif

USES=		bison cpe compiler:c++11-lib meson pkgconfig python:build shebangfix
CPE_VENDOR=	mesa3d
USE_GITLAB=	yes
USE_LDCONFIG=	yes
GL_SITE=	https://gitlab.freedesktop.org
BINARY_ALIAS=	python=${PYTHON_CMD}
SHEBANG_FILES=	src/vulkan/overlay-layer/${PORTNAME}-overlay-control.py
MESON_ARGS=	-Dgallium-omx=disabled \
		-Dgallium-xa=disabled \
		-Dandroid-libbacktrace=disabled \
		-Dlmsensors=disabled \
		-Dmicrosoft-clc=disabled \
		-Dvalgrind=disabled \
		-Dglvnd=true \
		-Dplatforms=${PLATFORMS:O:[-1..1]:ts,} \
		-Dvideo-codecs=all \
		${NULL}
LDFLAGS+=	-Wl,--undefined-version # https://gitlab.freedesktop.org/mesa/mesa/-/issues/8003
PLIST_SUB=	ARCH=${ARCH:S/amd/x86_/}

OPTIONS_DEFINE=		LIBUNWIND LLVM LTO OPENCL VAAPI VDPAU VKLAYERS WAYLAND X11 ZSTD
OPTIONS_DEFAULT=	LIBUNWIND LLVM LTO OPENCL VAAPI VDPAU VKLAYERS WAYLAND X11 ZSTD
OPTIONS_GROUP=		GALLIUM VULKAN
OPTIONS_GROUP_GALLIUM=	crocus iris panfrost r600 radeonsi
OPTIONS_GROUP_VULKAN=	anv hasvk radv
OPTIONS_EXCLUDE_DragonFly=	LIBUNWIND anv hasvk
OPTIONS_EXCLUDE_i386=	LTO # anv: vkcube fails on vkCreateSwapchainKHR
OPTIONS_EXCLUDE+=	${ARCH:Naarch64:C/.+/panfrost/}
OPTIONS_EXCLUDE+=	${ARCH:Namd64:Ni386:Nx86_64:C/.+/crocus hasvk/}
OPTIONS_EXCLUDE+=	${ARCH:Naarch64:Namd64:Ni386:Nx86_64:C/.+/anv iris/}
OPTIONS_EXCLUDE+=	${ARCH:Naarch64:Namd64:Ni386:Npowerpc64:Npowerpc64le:Nx86_64:C/.+/LIBUNWIND/}
OPTIONS_EXCLUDE+=	${"${GL_DEFAULT:S/,/ /g:[-1]}"==${.CURDIR:T}:?COINST:}
OPTIONS_SLAVE+=		${"${GL_DEFAULT:S/,/ /g:[-1]}"!=${.CURDIR:T}:?COINST:}
OPTIONS_SUB=		yes

# Convert options to -D<type>-drivers=<driver1,driver2,etc>
.for i in ${OPTIONS_GROUP}
MESON_ARGS+=		-D${i:tl}-drivers=${${i}_DRIVERS:ts,}
. for j in ${OPTIONS_GROUP_${i}}
OPTIONS_DEFAULT+=	${j}
${j}_VARS+=		${i}_DRIVERS+=${j:S/anv/intel/:S/hasvk/intel_&/:S/radv/amd/}
. endfor
.endfor

GALLIUM_DESC=		Unified OpenGL drivers
crocus_DESC=		Broadwater, Eaglelake, Ironlake, Sandybridge, Ivybridge, Haswell
iris_DESC=		Broadwell and newer
panfrost_DESC=		Midgard, Bifrost
r600_DESC=		R600, R700, Evergreen, Northern Islands (implies LLVM)
radeonsi_DESC=		Southern Islands and newer (implies LLVM)

VULKAN_DESC=		Vulkan drivers
anv_DESC=		Skylake and newer
hasvk_DESC=		Ivy Bridge, Haswell, Broadwell
radv_DESC=		Southern Islands and newer (implies LLVM)
radv_BUILD_DEPENDS=	glslangValidator:graphics/glslang

COINST_DESC=		Allow co-installation with another Mesa port
COINST_MESON_ON=	-Degl-lib-suffix=${PKGNAMESUFFIX}
COINST_RUN_DEPENDS=	mesa-dri>0:graphics/mesa-dri # ICD
COINST_PLIST_SUB=	SUFFIX=${PKGNAMESUFFIX}
COINST_SUB_FILES=	libmap.conf
COINST_SUB_LIST=	SUFFIX=${PKGNAMESUFFIX}
COINST_PLIST_SUB_OFF=	SUFFIX=

LIBUNWIND_DESC=		Use libunwind for stacktraces
LIBUNWIND_LIB_DEPENDS=	libunwind.so:devel/libunwind
LIBUNWIND_MESON_ENABLED=	libunwind

LLVM_DESC=		Build with LLVM support (see implies)
LLVM_USES=		llvm:min=15,lib,noexport
LLVM_CONFIGURE_ENV=	LLVM_CONFIG=${LLVM_CONFIG}
LLVM_MESON_ENABLED=	llvm
.for i in r600 radeonsi radv
${i}_IMPLIES+=		LLVM
.endfor

LTO_MESON_TRUE=		b_lto

OPENCL_DESC=		Heterogeneous computing via OpenCL (implies LLVM)
OPENCL_BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli \
			libclc>0:devel/libclc \
			spirv-tools>0:graphics/spirv-tools \
			rustc:lang/${RUST_DEFAULT}
OPENCL_LIB_DEPENDS=	libLLVMSPIRVLib.so.${LLVM_VERSION}:devel/spirv-llvm-translator@${LLVM_PORT:T}
OPENCL_RUN_DEPENDS=	libclc>0:devel/libclc
OPENCL_CONFIGURE_ENV=	PKG_CONFIG_PATH="${LLVM_PREFIX}/libdata/pkgconfig"
OPENCL_MESON_FALSE=	b_lundef # environ
OPENCL_MESON_TRUE=	gallium-rusticl
OPENCL_MESON_ON=	-Dgallium-opencl=icd
OPENCL_MESON_OFF=	-Dgallium-opencl=disabled
OPENCL_VARS=		LLVM_USES=llvm:15,lib,noexport # chase libclc + rust (LTO)
OPENCL_VARS+=		COINST_RUN_DEPENDS+=clover>0:lang/clover # ICD
OPENCL_IMPLIES=		LLVM ${"${PORT_OPTIONS:Miris}":?iris:radeonsi} # any from OPTIONS_GROUP_GALLIUM

VAAPI_DESC=		Hardware encoding/decoding (only r600, radeonsi)
VAAPI_BUILD_DEPENDS=	libva>0:multimedia/libva
VAAPI_MESON_ENABLED=	gallium-va

VDPAU_DESC=		Hardware decoding (only r600, radeonsi) (implies X11)
VDPAU_BUILD_DEPENDS=	libvdpau>0:multimedia/libvdpau
VDPAU_MESON_ENABLED=	gallium-vdpau
VDPAU_IMPLIES=		X11

VKLAYERS_DESC=		Vulkan layers: ${VKLAYERS_MESON_ON:C/.*=//} (implies ${VKLAYERS_IMPLIES})
VKLAYERS_BUILD_DEPENDS=	glslangValidator:graphics/glslang
VKLAYERS_MESON_ON=	-Dvulkan-layers=device-select,overlay
VKLAYERS_IMPLIES=	${"${PORT_OPTIONS:Manv}":?anv:radv} # any from OPTIONS_GROUP_VULKAN

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-server.so:graphics/wayland
WAYLAND_VARS=		PLATFORMS+=wayland

X11_USES=		xorg
X11_USE=		XORG=x11,xcb,xdamage,xext,xfixes,xorgproto,xrandr,xshmfence,xxf86vm
X11_VARS=		PLATFORMS+=x11
X11_MESON_OFF=		-Dglx=disabled -Dxlib-lease=disabled

ZSTD_DESC=		Use ZSTD for shader cache
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ENABLED=	zstd

post-patch:
# Extract (snapshot) version from the port instead of empty string
	@${REINPLACE_CMD} '/MESA_GIT_SHA1/s/""/" (git-${DISTVERSIONSUFFIX:C/.*-g//})"/' \
		${WRKSRC}/bin/git_sha1_gen.py

post-patch-COINST-on:
	@${MV} ${WRKSRC}/src/gallium/targets/opencl/MesaOpenCL.def.in \
		${WRKSRC}/src/gallium/targets/opencl/MesaOpenCL${PKGNAMESUFFIX}.def.in
	@${MV} ${WRKSRC}/src/util/00-${PORTNAME}-defaults.conf \
		${WRKSRC}/src/util/00-${PKGBASE}-defaults.conf
	@${MV} ${WRKSRC}/src/util/00-radv-defaults.conf \
		${WRKSRC}/src/util/00-radv${PKGNAMESUFFIX}-defaults.conf

post-install-COINST-on:
	@${INSTALL_DATA} ${WRKDIR}/libmap.conf \
		${STAGEDIR}${PREFIX}/etc/libmap.d/${PKGBASE}.conf

.include <bsd.port.mk>
