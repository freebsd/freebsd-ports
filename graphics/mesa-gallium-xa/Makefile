PORTNAME=	mesa-gallium-xa
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	Mesa Gallium XA state tracker
WWW=		https://www.mesa3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.rst

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	used only by VMware supported architectures

USES=		llvm:lib,noexport xorg
USE_XORG=	xorgproto

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

MESON_ARGS+=	-Dgallium-drivers="svga" \
		-Dvulkan-drivers="" \
		-Dplatforms="" \
		-Dandroid-libbacktrace=disabled \
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
		-Dlmsensors=disabled \
		-Dmicrosoft-clc=disabled \
		-Dopengl=false \
		-Dshared-glapi=disabled \
		-Dosmesa=false \
		-Dvalgrind=disabled \
		-Dglvnd=disabled \
		-Dxlib-lease=disabled

LDFLAGS_i386=		-Wl,-znotext

MESON_ARGS+=	-Dgallium-xa=enabled

.if ${ARCH} != amd64
MESON_ARGS+=	-Dintel-rt=disabled # https://gitlab.freedesktop.org/mesa/mesa/-/issues/10629
.endif

.include <bsd.port.post.mk>
