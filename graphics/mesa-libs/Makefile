PORTNAME=	mesa-libs
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL libraries that support GLX and EGL clients
WWW=		https://www.mesa3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.rst

USES=		llvm:noexport

BUILD_DEPENDS=	libglvnd>=0:graphics/libglvnd \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		libclc-${LLVM_PORT:T}>0:devel/libclc@${LLVM_PORT:T} \
		spirv-tools>0:graphics/spirv-tools \
		spirv-llvm-translator-${LLVM_PORT:T}>0:devel/spirv-llvm-translator@${LLVM_PORT:T} \
		libva>=0:multimedia/libva
LIB_DEPENDS=	libdisplay-info.so:sysutils/libdisplay-info
RUN_DEPENDS=	spirv-tools>0:graphics/spirv-tools \
		spirv-llvm-translator-${LLVM_PORT:T}>0:devel/spirv-llvm-translator@${LLVM_PORT:T}

OPTIONS_GROUP=		PLATFORM
OPTIONS_GROUP_PLATFORM=	X11 WAYLAND
X11_DESC=		Enable X11 support for GBM/EGL
WAYLAND_DESC=		Enable Wayland support for GBM/EGL
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.8:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-server.so:graphics/wayland

OPTIONS_DEFINE=		ZSTD
OPTIONS_DEFAULT=	WAYLAND X11 ZSTD
OPTIONS_SUB=		yes

ZSTD_DESC=		Use ZSTD for shader cache
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ENABLED=	zstd

USE_LDCONFIG=		yes

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

LDFLAGS_i386=	-Wl,-znotext

# mesa-libs is the home of libgallium-${MESAVERSION}.so (the unified gallium
# runtime introduced in mesa 25's "megalib" refactor). It must be built with
# a real gallium driver set so install_megadrivers actually ships the lib;
# the per-driver lib/dri/*_dri.so shims that fall out of this build are
# stripped in post-install (they belong to graphics/mesa-dri).
GALLIUM_DRIVERS=	crocus i915 iris llvmpipe panfrost r300 r600 radeonsi \
			svga virgl zink
.if ${ARCH} != amd64 && ${ARCH} != i386 && ${ARCH} != x86_64
GALLIUM_DRIVERS:=	${GALLIUM_DRIVERS:Ncrocus:Ni915:Niris:Nsvga}
.endif
.if ${ARCH} == armv7
# These require llvm to be compiled with the amdgpu backend, which is not default on armv7
GALLIUM_DRIVERS:=       ${GALLIUM_DRIVERS:Nr600:Nradeonsi}
.endif

MESON_ARGS+=	-Dgallium-drivers=${GALLIUM_DRIVERS:ts,}
MESON_ARGS+=	-Dvulkan-drivers=""

MESON_ARGS+=	-Dvideo-codecs="all"

MESON_ARGS+=	-Dandroid-libbacktrace=disabled \
		-Dlmsensors=disabled \
		-Dmicrosoft-clc=disabled \
		-Dtools="" \
		-Dvalgrind=disabled

.if ${PORT_OPTIONS:MX11}
MESA_PLATFORMS+=	x11
USE_XORG+=		xorgproto x11 xcb xdamage xext \
			xfixes xshmfence xxf86vm xrandr
PLIST_SUB+=		GLX=""
.else
MESON_ARGS+=	-Dglx=disabled -Dxlib-lease=disabled
PLIST_SUB+=	GLX="@comment "
.endif

.if ${PORT_OPTIONS:MWAYLAND}
MESA_PLATFORMS+=	wayland
.endif

MESON_ARGS+=	-Dplatforms="${MESA_PLATFORMS:ts,:tl}"

.if ${ARCH} != amd64
MESON_ARGS+=	-Dintel-rt=disabled # https://gitlab.freedesktop.org/mesa/mesa/-/issues/10629
.endif

.if ${ARCH} == "i386"
# PR230239 Fix the build for i386 when WITH_LLD_IS_LD is set
LDFLAGS+=-Wl,-z,notext
.endif

PLIST_SUB+=	MESAVERSION=${MESAVERSION}

post-install:
# Fallback if GLX_EXT_libglvnd is missing or vendor library doesn't exist
	@${ECHO_CMD} "libGLX_indirect.so.0 libGLX_mesa.so.0" \
		>${STAGEDIR}${PREFIX}/etc/libmap.d/mesa.conf
# Strip the per-hardware DRI shims; they are owned by graphics/mesa-dri.
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/dri

.include <bsd.port.post.mk>
