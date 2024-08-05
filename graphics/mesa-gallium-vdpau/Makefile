PORTNAME=	mesa-gallium-vdpau
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	Mesa Gallium VDPAU drivers
WWW=		https://www.mesa3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.rst

ONLY_FOR_ARCHS=		aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	used only by AMD/Radeon hardware

BUILD_DEPENDS=	libvdpau>=0:multimedia/libvdpau
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		llvm:lib,noexport

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11
X11_DESC=		Enable X11 support
X11_USES=		xorg
X11_USE=		xorg=xorgproto,x11,xcb,xdamage,xext,xfixes,xshmfence,xxf86vm,xrandr

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

MESON_ARGS+=	-Dgallium-drivers="r600,radeonsi" \
		-Dvulkan-drivers="" \
		-Dandroid-libbacktrace=disabled \
		-Dgallium-va=disabled \
		-Dgallium-omx=disabled \
		-Dgallium-xa=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-nine=false \
		-Dgbm=disabled \
		-Dgles1=disabled \
		-Dgles2=disabled \
		-Dglvnd=disabled \
		-Dlmsensors=disabled \
		-Dmicrosoft-clc=disabled \
		-Dosmesa=false \
		-Dvalgrind=disabled \
		-Dglx=disabled \
		-Ddri3=enabled

LDFLAGS_i386=	-Wl,-znotext

MESON_ARGS+=	-Dgallium-vdpau=enabled

.if ${PORT_OPTIONS:MX11}
MESON_ARGS+=	-Dplatforms="x11"
.else
MESON_ARGS+=	-Dglx=disabled \
		-Degl=disabled \
		-Dopengl=false \
		-Dshared-glapi=disabled \
		-Dplatforms=""
.endif

.include <bsd.port.post.mk>
