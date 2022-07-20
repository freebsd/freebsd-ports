PORTNAME=	mesa-dri
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for DRI2+

OPTIONS_GROUP=			PLATFORM
OPTIONS_GROUP_PLATFORM=		PLATFORM_X11 PLATFORM_WAYLAND
PLATFORM_X11_DESC=		Enable X11 support for GBM/EGL
PLATFORM_WAYLAND_DESC=		Enable Wayland support for GBM/EGL
PLATFORM_WAYLAND_IMPLIES=	WAYLAND

OPTIONS_DEFINE=		WAYLAND ZSTD
OPTIONS_DEFAULT=	WAYLAND PLATFORM_X11 PLATFORM_WAYLAND ZSTD
OPTIONS_SUB=		yes

WAYLAND_DESC=		Enable support for the Wayland platform in Vulkan drivers
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.8:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_IMPLIES=	PLATFORM_WAYLAND

ZSTD_DESC=		Use ZSTD for shader cache
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ENABLED=	zstd

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

ALL_DRI_DRIVERS=	I915 I965 R100 R200
ALL_GALLIUM_DRIVERS=	CROCUS IRIS PANFROST R300 R600 RADEONSI SVGA SWRAST
ALL_VULKAN_DRIVERS=	INTEL AMD SWRAST

GALLIUM_DRIVERS+=	SWRAST	# llvmpipe
VULKAN_DRIVERS+=	SWRAST	# lavapipe

.if ${ARCH:Marm*}
DRI_DRIVERS+=	R100
.endif

.if ${ARCH} == aarch64
GALLIUM_DRIVERS+=	PANFROST
.endif

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386 \
 || ${ARCH:Mpowerpc*} || ${ARCH} == riscv64
DRI_DRIVERS+=		R100 R200
GALLIUM_DRIVERS+=	R300 R600 RADEONSI
VULKAN_DRIVERS+=	AMD
. if ${PORT_OPTIONS:MPLATFORM_X11}
USE_XORG+=		xv xvmc
MESON_ARGS+=		-Dgallium-xvmc=enabled
. endif
.endif
.if ${ARCH} == amd64 || ${ARCH} == i386
DRI_DRIVERS+=		I915 I965
GALLIUM_DRIVERS+=	CROCUS IRIS SVGA
VULKAN_DRIVERS+=	INTEL
.endif

LDFLAGS_i386=		-Wl,-znotext

.if ${PORT_OPTIONS:MPLATFORM_X11}
MESA_PLATFORMS+=	x11
USE_XORG+=		xorgproto x11 xdamage xext xfixes xshmfence xv
.if defined(VULKAN_DRIVERS)
USE_XORG+=		xcb xrandr
.endif
.endif

.if ${PORT_OPTIONS:MPLATFORM_WAYLAND}
MESA_PLATFORMS+=	wayland
.endif

MESON_ARGS+=	-Ddri-drivers="${DRI_DRIVERS:ts,:tl}" \
		-Dgallium-drivers="${GALLIUM_DRIVERS:ts,:tl}" \
		-Dvulkan-drivers="${VULKAN_DRIVERS:ts,:tl}" \
		-Dplatforms="${MESA_PLATFORMS:ts,:tl}"

# Disable some options
MESON_ARGS+=	-Dgallium-xa=disabled \
		-Dgallium-vdpau=disabled \
		-Dgallium-va=disabled \
		-Dgles1=disabled \
		-Dgles2=disabled \
		-Dglx=disabled \
		-Degl=disabled \
		-Dosmesa=false \
		-Dtools=""

.for _d in ${ALL_DRI_DRIVERS}
. if defined(DRI_DRIVERS) && ${DRI_DRIVERS:M${_d}}
PLIST_SUB+=	${_d}_DRIVER=""
. else
PLIST_SUB+=	${_d}_DRIVER="@comment "
. endif
.endfor

.for _gd in ${ALL_GALLIUM_DRIVERS}
. if defined(GALLIUM_DRIVERS) && ${GALLIUM_DRIVERS:M${_gd}}
PLIST_SUB+=	${_gd}_GDRIVER=""
. else
PLIST_SUB+=	${_gd}_GDRIVER="@comment "
. endif
.endfor

PLIST_SUB += ARCH=${ARCH:S/amd/x86_/}
.for _vd in ${ALL_VULKAN_DRIVERS}
. if defined(VULKAN_DRIVERS) && ${VULKAN_DRIVERS:M${_vd}}
PLIST_SUB+=	${_vd}_VDRIVER=""
. else
PLIST_SUB+=	${_vd}_VDRIVER="@comment "
. endif
.endfor

.include "${MASTERDIR}/Makefile.targets"

post-install:
	@${RM} -r ${STAGEDIR}/etc/OpenCL
	${INSTALL_DATA} ${FILESDIR}/01-freebsd.conf \
		${STAGEDIR}${PREFIX}/share/drirc.d

.include <bsd.port.post.mk>
