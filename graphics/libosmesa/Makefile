# Created by: gahr
# $FreeBSD$

PORTNAME=	libosmesa
PORTVERSION=	${MESAVERSION}
PORTREVISION=	2
CATEGORIES=	graphics

COMMENT=	Off-Screen Mesa implementation of the OpenGL API

USE_XORG=	xorgproto

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

CONFIGURE_ARGS+=	--disable-dri --disable-egl --disable-gbm \
			--disable-gles2 --with-gallium-drivers=swrast
MESA_BUILD_WRKSRC=	src/util src/compiler src/mapi src/mesa
LDFLAGS_i386=		-Wl,-znotext

.if "${MESA_LLVM_VER}" != ""
CONFIGURE_ARGS+=	--enable-osmesa-gallium
MESA_BUILD_WRKSRC+=	src/gallium
MESA_INSTALL_WRKSRC=	src/gallium/state_trackers/osmesa src/gallium/targets/osmesa
.else
CONFIGURE_ARGS+=	--enable-osmesa
MESA_INSTALL_WRKSRC=	src/mesa/drivers/osmesa
.endif

.include "${MASTERDIR}/Makefile.targets"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/osmesa.h \
		${STAGEDIR}${PREFIX}/include/GL

.include <bsd.port.post.mk>
