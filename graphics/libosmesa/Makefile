# Created by: gahr
# $FreeBSD$

PORTNAME=	libosmesa
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	Off-Screen Mesa implementation of the OpenGL API

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libglapi.so:graphics/libglapi

USE_XORG=	x11 xau xcb xdmcp xvmc
# libosmesa doesn't link agains libGL but osmesa.h needs GL/gl.h
# and both headers are intalled by libGL ....
USE_GL=		gl

.include <bsd.port.options.mk>

.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

#MESA_BUILD_WRKSRC=	src/util src/glsl src/mesa #/drivers/osmesa
MESA_INSTALL_WRKSRC=	src/mesa/drivers/osmesa

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/osmesa.h \
		${STAGEDIR}${PREFIX}/include/GL

.include <bsd.port.mk>
