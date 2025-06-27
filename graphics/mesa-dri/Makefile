PORTNAME=	mesa-dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	8
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for DRI2+
WWW=		https://www.mesa3d.org/

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR}

LIB_DEPENDS+=	libglapi.so:graphics/mesa-libs

USES+=		llvm:lib,noexport

OPTIONS_DEFINE=		ZSTD
OPTIONS_GROUP=		GALLIUM PLATFORM VULKAN
OPTIONS_DEFAULT=	WAYLAND X11 ZSTD
OPTIONS_SUB=		yes

ZSTD_DESC=		Use ZSTD for shader cache
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ENABLED=	zstd

OPTIONS_GROUP_PLATFORM=	X11 WAYLAND
X11_DESC=		Enable X11 support for GBM/EGL
WAYLAND_DESC=		Enable Wayland support for GBM/EGL and Vulkan
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.8:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland

OPTIONS_GROUP_GALLIUM=	crocus i915 iris panfrost r300 r600 radeonsi svga swrast zink
GALLIUM_DESC=		Unified OpenGL drivers
crocus_DESC=		Intel GPU Gen4 (Broadwater) to Gen7 (Haswell)
i915_DESC=		Intel GPU Gen3 (Grantsdale to Pineview)
iris_DESC=		Intel GPU Gen8 (Broadwell) and newer
iris_BUILD_DEPENDS=	libclc-${LLVM_PORT:T}>0:devel/libclc@${LLVM_PORT:T} \
			spirv-tools>0:graphics/spirv-tools \
			spirv-llvm-translator-${LLVM_PORT:T}>0:devel/spirv-llvm-translator@${LLVM_PORT:T}
iris_RUN_DEPENDS=	spirv-tools>0:graphics/spirv-tools \
			spirv-llvm-translator-${LLVM_PORT:T}>0:devel/spirv-llvm-translator@${LLVM_PORT:T}
iris_CONFIGURE_ENV=	PKG_CONFIG_PATH="${LLVM_PREFIX}/libdata/pkgconfig"
iris_IMPLIES=		SPIRV
panfrost_DESC=		ARM Midgard and Bifrost
r300_DESC=		AMD/ATI R300, R400 and R500
r600_DESC=		AMD/ATI R600, R700, Evergreen, Northern Islands
radeonsi_DESC=		AMD/ATI Southern Islands and newer
svga_DESC=		VMWare Virtual GPU
swrast_DESC=		Software Rasterizer
zink_DESC=		OpenGL on top of Khronos’ Vulkan API

OPTIONS_EXCLUDE+=	${ARCH:Marmv7:C/.+/crocus i915 iris panfrost r300 r600 radeonsi svga zink/}
OPTIONS_EXCLUDE+=	${ARCH:Naarch64:C/.+/panfrost/}
OPTIONS_EXCLUDE+=	${ARCH:Namd64:Ni386:Nx86_64:C/.+/crocus i915 iris svga/}
MESON_ARGS+=		-Dgallium-drivers=${GALLIUM_DRIVERS:ts,}
. for _gd in ${OPTIONS_GROUP_GALLIUM}
OPTIONS_DEFAULT+=	${_gd}
${_gd}_VARS+=		GALLIUM_DRIVERS+=${_gd}
. endfor

OPTIONS_GROUP_VULKAN=	anv radv swrast_vk
VULKAN_DESC=		Vulkan drivers
anv_DESC=		Intel GPU Gen9 and newer Vulkan support
anv_BUILD_DEPENDS=	glslangValidator:graphics/glslang \
			libclc-${LLVM_PORT:T}>0:devel/libclc@${LLVM_PORT:T} \
			spirv-tools>0:graphics/spirv-tools \
			spirv-llvm-translator-${LLVM_PORT:T}>0:devel/spirv-llvm-translator@${LLVM_PORT:T}
anv_RUN_DEPENDS=	spirv-tools>0:graphics/spirv-tools \
			spirv-llvm-translator-${LLVM_PORT:T}>0:devel/spirv-llvm-translator@${LLVM_PORT:T}
anv_CONFIGURE_ENV=	PKG_CONFIG_PATH="${LLVM_PREFIX}/libdata/pkgconfig"
radv_DESC=		AMD/ATI Southern Islands and newer Vulkan support
radv_BUILD_DEPENDS=	glslangValidator:graphics/glslang
swrast_vk_DESC=		Software Rasterizer Vulkan support

OPTIONS_EXCLUDE+=	${ARCH:Marmv7:C/.+/anv radv/}
OPTIONS_EXCLUDE+=	${ARCH:Namd64:Ni386:Nx86_64:C/.+/anv/}
MESON_ARGS+=		-Dvulkan-drivers=${VULKAN_DRIVERS:ts,}
. for _vd in ${OPTIONS_GROUP_VULKAN}
OPTIONS_DEFAULT+=	${_vd}
${_vd}_VARS+=		VULKAN_DRIVERS+=${_vd:S/anv/intel/:S/radv/amd/:S/swrast_vk/swrast/}
. endfor

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

LDFLAGS_i386=		-Wl,-znotext

.if ${PORT_OPTIONS:MX11}
MESA_PLATFORMS+=	x11
USE_XORG+=		xcb xorgproto xrandr x11 xdamage xext xfixes xshmfence xv
.else
MESON_ARGS+=		-Dxlib-lease=disabled
.endif

.if ${PORT_OPTIONS:MWAYLAND}
MESA_PLATFORMS+=	wayland
.endif

MESON_ARGS+=	-Dplatforms="${MESA_PLATFORMS:ts,:tl}"

# Vulkan Video extensions (keep in sync with mesa-gallium-va)
MESON_ARGS+=	-Dvideo-codecs="vc1dec,h264dec,h264enc,h265dec,h265enc,av1dec,av1enc,vp9dec"

# Disable some options
MESON_ARGS+=	-Dandroid-libbacktrace=disabled \
		-Dgallium-xa=disabled \
		-Dgallium-vdpau=disabled \
		-Dgallium-va=disabled \
		-Dgles1=enabled \
		-Dgles2=enabled \
		-Dglvnd=disabled \
		-Dglx=disabled \
		-Degl=enabled \
		-Dlmsensors=disabled \
		-Dmicrosoft-clc=disabled \
		-Dosmesa=false \
		-Dvalgrind=disabled

.if ${ARCH} != amd64
MESON_ARGS+=	-Dintel-rt=disabled # https://gitlab.freedesktop.org/mesa/mesa/-/issues/10629
.endif

.for _gd in ${OPTIONS_GROUP_GALLIUM}
. if defined(GALLIUM_DRIVERS) && ${GALLIUM_DRIVERS:M${_gd}}
PLIST_SUB+=	${_gd}=""
. else
PLIST_SUB+=	${_gd}="@comment "
. endif
.endfor

PLIST_SUB += ARCH=${ARCH:S/amd/x86_/}
.for _vd in ${OPTIONS_GROUP_VULKAN}
. if defined(VULKAN_DRIVERS) && ${VULKAN_DRIVERS:M${_vd}}
PLIST_SUB+=	${_vd}=""
. else
PLIST_SUB+=	${_vd}="@comment "
. endif
.endfor

post-install:
	@${RM} -r ${STAGEDIR}/etc/OpenCL
	${INSTALL_DATA} ${FILESDIR}/01-freebsd.conf \
		${STAGEDIR}${PREFIX}/share/drirc.d

.include <bsd.port.post.mk>
