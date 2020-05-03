# Created by: johalun
# $FreeBSD$

PORTNAME=	libxatracker
PORTVERSION=	${MESAVERSION}
PORTREVISION=	2
CATEGORIES=	graphics

COMMENT=	Mesa XA state tracker

USES=		xorg
USE_XORG=	xorgproto

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	Used only by VMWare supported architectures

CONFIGURE_ARGS+=	--disable-dri \
			--disable-egl \
			--disable-gbm \
			--disable-gles2 \
			--disable-glx \
			--disable-opengl \
			--disable-shared-glapi \
			--with-gallium-drivers= \
			--with-platforms=

MESA_BUILD_WRKSRC=	src/util src/compiler
LDFLAGS_i386=		-Wl,-znotext

CONFIGURE_ARGS+=	--enable-xa
MESA_BUILD_WRKSRC+=	src/gallium
MESA_INSTALL_WRKSRC=	src/gallium/state_trackers/xa src/gallium/targets/xa

.include "${MASTERDIR}/Makefile.targets"
.include <bsd.port.post.mk>
