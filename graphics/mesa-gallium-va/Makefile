# $FreeBSD$

PORTNAME=	mesa-gallium-va
PORTVERSION=	${MESAVERSION}
PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	Mesa Gallium VAAPI drivers

USES=		xorg
USE_XORG=	xcb xfixes xrandr

LIB_DEPENDS=	libva.so:multimedia/libva \
		libzstd.so:archivers/zstd
BUILD_DEPENDS=	wayland-protocols>=1.8:graphics/wayland-protocols

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

ONLY_FOR_ARCHS=		i386 amd64 aarch64 powerpc64
ONLY_FOR_ARCHS_REASON=	Used only by amd/radeon hardware

MESON_ARGS+=	-Ddri-drivers="" \
		-Dgallium-drivers="radeonsi,r600" \
		-Dvulkan-drivers="" \
		-Dgallium-vdpau=disabled \
		-Dgallium-omx=disabled \
		-Dgallium-xa=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-xvmc=disabled \
		-Dgallium-nine=false \
		-Degl=disabled \
		-Dgbm=disabled \
		-Dgles2=disabled \
		-Dglx=disabled \
		-Dopengl=false \
		-Dshared-glapi=disabled \
		-Dosmesa=none

LDFLAGS_i386=		-Wl,-znotext

MESON_ARGS+=	-Dgallium-va=enabled

.include "${MASTERDIR}/Makefile.targets"
.include <bsd.port.post.mk>
