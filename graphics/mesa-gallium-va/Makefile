PORTNAME=	mesa-gallium-va
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	Mesa Gallium VAAPI drivers
WWW=		https://www.mesa3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.rst

ONLY_FOR_ARCHS=		aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	used only by AMD/Radeon hardware

BUILD_DEPENDS=	libva>=0:multimedia/libva
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		llvm:lib,noexport

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11
X11_DESC=		Enable X11 support
X11_USES=		xorg
X11_USE=		xorg=xorgproto,x11,xcb,xdamage,xext,xfixes,xshmfence,xxf86vm,xrandr

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

MESON_ARGS+=	-Dvideo-codecs="vc1dec,h264dec,h264enc,h265dec,h265enc,av1dec,av1enc,vp9dec" \
		-Dgallium-drivers="radeonsi,r600" \
		-Dvulkan-drivers="" \
		-Dandroid-libbacktrace=disabled \
		-Dgallium-vdpau=disabled \
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

MESON_ARGS+=	-Dgallium-va=enabled

.if ${ARCH} != amd64
MESON_ARGS+=	-Dintel-rt=disabled # https://gitlab.freedesktop.org/mesa/mesa/-/issues/10629
.endif

.if ${PORT_OPTIONS:MX11}
MESON_ARGS+=	-Dplatforms="x11"
.else
MESON_ARGS+=	-Dglx=disabled \
		-Degl=disabled \
		-Dopengl=false \
		-Dshared-glapi=disabled \
		-Dxlib-lease=disabled \
		-Dplatforms=""
.endif

.include <bsd.port.post.mk>
