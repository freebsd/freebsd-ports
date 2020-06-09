# Created by: johalun
# $FreeBSD$

PORTNAME=	libxatracker
PORTVERSION=	${MESAVERSION}
PORTREVISION=	3
CATEGORIES=	graphics

COMMENT=	Mesa XA state tracker

USES=		xorg
USE_XORG=	xorgproto

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	Used only by VMWare supported architectures

MESON_ARGS+=	-Ddri-drivers="" \
		-Dgallium-drivers="svga" \
		-Dvulkan-drivers="" \
		-Dgallium-vdpau=false \
		-Dgallium-omx=disabled \
		-Dgallium-va=false \
		-Dgallium-opencl=disabled \
		-Dgallium-xvmc=false \
		-Dgallium-nine=false \
		-Degl=false \
		-Dgbm=false \
		-Dgles2=false \
		-Dglx=disabled \
		-Dopengl=false \
		-Dshared-glapi=false \
		-Dosmesa=none \
		-Dplatforms=

LDFLAGS_i386=		-Wl,-znotext

MESA_ARGS+=	-Dgallium-xa=true

.include "${MASTERDIR}/Makefile.targets"
.include <bsd.port.post.mk>
