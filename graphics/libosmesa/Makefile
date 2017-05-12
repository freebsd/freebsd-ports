# Created by: gahr
# $FreeBSD$

PORTNAME=	libosmesa
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	Off-Screen Mesa implementation of the OpenGL API

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libglapi.so:graphics/mesa-libs

USE_XORG=	glproto

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/mesa-dri/Makefile.common"

CONFIGURE_ARGS+=	--disable-dri --disable-egl --disable-gbm \
			--with-gallium-drivers=swrast
MESA_BUILD_WRKSRC=	src/util src/compiler src/mapi src/mesa

.if "${MESA_LLVM_VER}" != ""
CONFGIURE_ARGS+=	--enable-osmesa-gallium
MESA_BUILD_WRKSRC+=	src/gallium
MESA_INSTALL_WRKSRC=	src/gallium/state_trackers/osmesa src/gallium/targets/osmesa
.else
CONFIGURE_ARGS+=	--enable-osmesa
MESA_INSTALL_WRKSRC=	src/mesa/drivers/osmesa
.endif

.include "${.CURDIR}/../../graphics/mesa-dri/Makefile.targets"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/osmesa.h \
		${STAGEDIR}${PREFIX}/include/GL

.include <bsd.port.mk>
