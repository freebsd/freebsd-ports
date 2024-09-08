PORTNAME=	mesa-libs
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL libraries that support GLX and EGL clients
WWW=		https://www.mesa3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.rst

USES=		llvm:noexport

BUILD_DEPENDS=	libglvnd>=0:graphics/libglvnd

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

MESON_ARGS+=	-Dandroid-libbacktrace=disabled \
		-Dgallium-vdpau=disabled \
		-Dgallium-omx=disabled \
		-Dgallium-va=disabled \
		-Dgallium-xa=disabled \
		-Dgallium-nine=false \
		-Dlmsensors=disabled \
		-Dmicrosoft-clc=disabled \
		-Dosmesa=false \
		-Dtools="" \
		-Dvalgrind=disabled \
		-Degl=enabled \
		-Dgbm=enabled \
		-Dvulkan-drivers="" \
		-Dglvnd=enabled
# Building EGL and GBM requires a driver so add r300
MESON_ARGS+=	-Dgallium-drivers="r300"

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

post-install:
# Fallback if GLX_EXT_libglvnd is missing or vendor library doesn't exist
	@${ECHO_CMD} "libGLX_indirect.so.0 libGLX_mesa.so.0" \
		>${STAGEDIR}${PREFIX}/etc/libmap.d/mesa.conf

.include <bsd.port.post.mk>
