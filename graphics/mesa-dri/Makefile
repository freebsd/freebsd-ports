# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mesa-dri
PORTVERSION=	${MESAVERSION}
PORTREVISION=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for DRI2+

USES=		xorg
USE_XORG=	xorgproto x11 xdamage xext xfixes xshmfence xv xvmc

OPTIONS_GROUP=			PLATFORM
OPTIONS_GROUP_PLATFORM=		PLATFORM_X11 PLATFORM_WAYLAND PLATFORM_DRM PLATFORM_SURFACELESS
PLATFORM_X11_DESC=		Enable X11 support for GBM/EGL
PLATFORM_WAYLAND_DESC=		Enable Wayland support for GBM/EGL
PLATFORM_DRM_DESC=		Enable DRM support for GBM/EGL
PLATFORM_SURFACELESS_DESC=	Enable Surfaceless support for GBM/EGL
PLATFORM_WAYLAND_IMPLIES=	WAYLAND

OPTIONS_DEFINE=	VAAPI VDPAU WAYLAND
OPTIONS_DEFAULT=WAYLAND PLATFORM_X11 PLATFORM_WAYLAND PLATFORM_DRM PLATFORM_SURFACELESS
OPTIONS_SUB=	yes

VAAPI_MESON_ON=		-Dgallium-va=true
VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_USE=		XORG=xcb

VDPAU_MESON_ON=		-Dgallium-vdpau=true
VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau

WAYLAND_DESC=		Enable support for the Wayland platform in Vulkan drivers
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.8:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_IMPLIES=	PLATFORM_WAYLAND

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

ALL_DRI_DRIVERS=	I915 I965 R100 R200 SWRAST
ALL_GALLIUM_DRIVERS=	R300 R600 RADEONSI SVGA SWRAST
ALL_VULKAN_DRIVERS=	INTEL AMD

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH:Marm*} || ${ARCH} == i386 || ${ARCH:Mmips*} || ${ARCH:Mpowerpc*}
GALLIUM_DRIVERS=	SWRAST	# llvmpipe
.else
GALLIUM_DRIVERS=	""
.endif
VULKAN_DRIVERS=		#

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386 \
 || ${ARCH} == powerpc || ${ARCH} == powerpc64
DRI_DRIVERS+=		R100 R200
GALLIUM_DRIVERS+=	R300 R600 RADEONSI
VULKAN_DRIVERS+=	AMD
MESON_ARGS+=		-Dgallium-xvmc=true
.endif
.if ${ARCH} == amd64 || ${ARCH} == i386
DRI_DRIVERS+=		I915 I965
GALLIUM_DRIVERS+=	SVGA
. if ${OPSYS} == FreeBSD
EXTRA_PATCHES+=	${PATCHDIR}/extra-src_mesa_drivers_dri_i965_intel__screen.c
. endif
VULKAN_DRIVERS+=	INTEL
.endif

.if ${VULKAN_DRIVERS}
BUILD_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR}
USE_XORG+=		xcb xrandr
.endif

LDFLAGS_i386=		-Wl,-znotext

.if ${PORT_OPTIONS:MPLATFORM_X11}
MESA_PLATFORMS+=	x11
.endif

.if ${PORT_OPTIONS:MPLATFORM_DRM}
MESA_PLATFORMS+=	drm
.endif

.if ${PORT_OPTIONS:MPLATFORM_SURFACELESS}
MESA_PLATFORMS+=	surfaceless
.endif

# .if ${PORT_OPTIONS:MPLATFORM_WAYLAND} && !${PORT_OPTIONS:MWAYLAND}
# .error "Platform Wayland is selected but Wayland support is disabled"
# .endif

MESON_ARGS+=	-Ddri-drivers="${DRI_DRIVERS:ts,:tl}" \
			-Dgallium-drivers="${GALLIUM_DRIVERS:ts,:tl}" \
			-Dvulkan-drivers="${VULKAN_DRIVERS:ts,:tl}" \
			-Dplatforms="${MESA_PLATFORMS:ts,:tl}"

# Disable some options
MESON_ARGS+=	-Dgallium-xa=false \
		-Dgles1=false \
		-Dgles2=false \
		-Dglx=disabled \
		-Degl=false \
		-Dosmesa=none \
		-Dtools=""

.for _d in ${ALL_DRI_DRIVERS}
. if ${DRI_DRIVERS:M${_d}}
PLIST_SUB+=	${_d}_DRIVER=""
. else
PLIST_SUB+=	${_d}_DRIVER="@comment "
. endif
.endfor

.for _gd in ${ALL_GALLIUM_DRIVERS}
. if ${GALLIUM_DRIVERS:M${_gd}}
PLIST_SUB+=	${_gd}_GDRIVER=""
. else
PLIST_SUB+=	${_gd}_GDRIVER="@comment "
. endif
.endfor

PLIST_SUB += ARCH=${ARCH:S/amd/x86_/}
.for _vd in ${ALL_VULKAN_DRIVERS}
. if ${VULKAN_DRIVERS:M${_vd}}
PLIST_SUB+=	${_vd}_VDRIVER=""
. else
PLIST_SUB+=	${_vd}_VDRIVER="@comment "
. endif
.endfor

.include "${MASTERDIR}/Makefile.targets"

post-install:
	@${RM} -r ${STAGEDIR}/etc/OpenCL

.include <bsd.port.post.mk>
