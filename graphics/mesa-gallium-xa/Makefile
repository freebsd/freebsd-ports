PORTNAME=	mesa-gallium-xa
PORTVERSION=	${MESAVERSION}
PORTREVISION=	2
CATEGORIES=	graphics

COMMENT=	Mesa Gallium XA state tracker
WWW=		https://www.mesa3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.rst

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	used only by VMware supported architectures

LIB_DEPENDS=	libLLVM-${LLVM_DEFAULT}.so:devel/llvm${LLVM_DEFAULT}

USES=		xorg
USE_XORG=	xorgproto

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

MESON_ARGS+=	-Ddri-drivers="" \
		-Dgallium-drivers="svga" \
		-Dvulkan-drivers="" \
		-Dplatforms="" \
		-Dgallium-vdpau=disabled \
		-Dgallium-omx=disabled \
		-Dgallium-va=disabled \
		-Dgallium-opencl=disabled \
		-Dgallium-nine=false \
		-Degl=disabled \
		-Dgbm=disabled \
		-Dgles1=disabled \
		-Dgles2=disabled \
		-Dglx=disabled \
		-Dopengl=false \
		-Dshared-glapi=disabled \
		-Dosmesa=false

LDFLAGS_i386=		-Wl,-znotext

MESON_ARGS+=	-Dgallium-xa=enabled

.include "${MASTERDIR}/Makefile.targets"
.include <bsd.port.post.mk>
