# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mesa-libs
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL libraries that support GLX and EGL clients

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS+=	libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2

USE_XORG=	dri2proto dri3proto glproto presentproto x11 xcb xdamage xext \
		xfixes xshmfence xxf86vm

OPTIONS_DEFINE=	WAYLAND
OPTIONS_SUB=	yes

WAYLAND_DESC=		Enable support for the Wayland platform in EGL
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-server.so:graphics/wayland

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/mesa-dri/Makefile.common"

CONFIGURE_ARGS+=	--with-dri-drivers=swrast --with-gallium-drivers=swrast

# libEGL needs gallium enabled which depends on llvm
.if "${MESA_LLVM_VER}" != ""
.if ${PORT_OPTIONS:MWAYLAND}
CONFIGURE_ARGS+=	--with-egl-platforms=x11,drm,wayland
.else
CONFIGURE_ARGS+=        --with-egl-platforms=x11,drm
.endif
PLIST_SUB+=		EGL=""	
.else
CONFIGURE_ARGS+=        --disable-egl
PLIST_SUB+=		EGL="@comment "
.if ${PORT_OPTIONS:MWAYLAND}
IGNORE= WAYLAND is an option for EGL and thus only valid on platforms with LLVM
.endif
.endif 

MESA_BUILD_WRKSRC=	src/mapi
MESA_INSTALL_WRKSRC=	src/mapi

.if ${PORT_OPTIONS:MWAYLAND}
MESA_BUILD_WRKSRC+=	src/egl/wayland/wayland-drm src/egl/wayland/wayland-egl
MESA_INSTALL_WRKSRC+=	src/egl/wayland/wayland-egl
.endif

MESA_BUILD_WRKSRC+=	src/gbm src/glx
MESA_INSTALL_WRKSRC+=	src/gbm src/glx

.if "${MESA_LLVM_VER}" != ""
MESA_BUILD_WRKSRC+=	src/egl
MESA_INSTALL_WRKSRC+=	src/egl
.endif

.include "${.CURDIR}/../../graphics/mesa-dri/Makefile.targets"

post-install:
	@cd ${WRKSRC}/src && ${SETENV} DESTDIR=${STAGEDIR} \
		${MAKE_CMD} install-pkgconfigDATA install-glHEADERS install-glxHEADERS

.include <bsd.port.mk>
