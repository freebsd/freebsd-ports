# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mesa-libs
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL libraries that support GLX and EGL clients

CONFLICTS_INSTALL=	libglvnd # include/GL/gl.h

USES=		xorg
USE_XORG=	xorgproto x11 xcb xdamage xext \
		xfixes xshmfence xxf86vm xrandr

OPTIONS_DEFINE=	WAYLAND
OPTIONS_DEFAULT=WAYLAND
OPTIONS_SUB=	yes

WAYLAND_DESC=		Enable support for the Wayland platform in EGL
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.8:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

MESON_ARGS+=	-Dgallium-drivers="" \
		-Dgallium-vdpau=false \
		-Dgallium-xvmc=false \
		-Dgallium-omx=disabled \
		-Dgallium-va=false \
		-Dgallium-xa=false \
		-Dgallium-nine=false \
		-Dgallium-clover=disabled \
		-Dosmesa=none \
		-Dtools="" \
		-Degl=true \
		-Dgbm=true \
		-Dvulkan-drivers=""
# Building EGL and GBM requires a dri driver so add swrast
MESON_ARGS+=	-Ddri-drivers="swrast"

.if ${PORT_OPTIONS:MWAYLAND}
MESON_ARGS+=	-Dplatforms=x11,surfaceless,drm,wayland
.endif

.if ${ARCH} == "i386"
# PR230239 Fix the build for i386 when WITH_LLD_IS_LD is set
LDFLAGS+=-Wl,-z,notext
.elif ${ARCH} == "powerpc"
USE_GCC=	yes
.endif

.include "${MASTERDIR}/Makefile.targets"

.include <bsd.port.post.mk>
