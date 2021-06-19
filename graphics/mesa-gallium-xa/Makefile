# Created by: johalun

PORTNAME=	mesa-gallium-xa
PORTVERSION=	${MESAVERSION}
PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	Mesa Gallium XA state tracker

USES=		xorg
USE_XORG=	xorgproto

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	Used only by VMWare supported architectures

MESON_ARGS+=	-Ddri-drivers="" \
		-Dgallium-drivers="svga" \
		-Dvulkan-drivers="" \
		-Dplatforms="" \
		-Dgallium-vdpau=disabled \
		-Dgallium-omx=disabled \
		-Dgallium-va=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-xvmc=disabled \
		-Dgallium-nine=false \
		-Degl=disabled \
		-Dgbm=disabled \
		-Dgles1=disabled \
		-Dgles2=disabled \
		-Dglx=disabled \
		-Dopengl=false \
		-Dshared-glapi=disabled \
		-Dosmesa=none

LDFLAGS_i386=		-Wl,-znotext

MESON_ARGS+=	-Dgallium-xa=enabled

.include "${MASTERDIR}/Makefile.targets"
.include <bsd.port.post.mk>
