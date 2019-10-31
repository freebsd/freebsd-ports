# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mesa-libs
PORTVERSION=	${MESAVERSION}
PORTREVISION=	3
CATEGORIES=	graphics

COMMENT=	OpenGL libraries that support GLX and EGL clients

USE_XORG=	xorgproto x11 xcb xdamage xext \
		xfixes xshmfence xxf86vm

OPTIONS_DEFINE=	WAYLAND
OPTIONS_DEFAULT=WAYLAND
OPTIONS_SUB=	yes

WAYLAND_DESC=		Enable support for the Wayland platform in EGL
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.8:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

CONFIGURE_ARGS+=	--with-dri-drivers="" --with-gallium-drivers=""

.if ${PORT_OPTIONS:MWAYLAND}
CONFIGURE_ARGS+=	--with-platforms=x11,surfaceless,drm,wayland
.endif

MESA_BUILD_WRKSRC=	src/mapi src/util
MESA_INSTALL_WRKSRC=	src/mapi

.if ${PORT_OPTIONS:MWAYLAND}
MESA_BUILD_WRKSRC+=	src/egl/wayland/wayland-drm
.endif

MESA_BUILD_WRKSRC+=	src/gbm src/glx
MESA_INSTALL_WRKSRC+=	src/gbm src/glx

MESA_BUILD_WRKSRC+=	src/egl
MESA_INSTALL_WRKSRC+=	src/egl

.if ${ARCH} == "i386"
# PR230239 Fix the build for i386 when WITH_LLD_IS_LD is set
LDFLAGS+=-Wl,-z,notext
.endif

.include "${MASTERDIR}/Makefile.targets"

post-install:
	@cd ${WRKSRC}/src && ${SETENV} DESTDIR=${STAGEDIR} \
		${MAKE_CMD} install-pkgconfigDATA install-glHEADERS install-glxHEADERS

.include <bsd.port.post.mk>
