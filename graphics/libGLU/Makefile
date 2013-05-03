# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	libGLU
PORTREVISION=	2
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL utility library

USE_GL=		gl
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

INSTALL_WRKSRC=	${WRKSRC}/src/glu
BUILD_WRKSRC=	${WRKSRC}/src/glu

pre-install:
	@${MKDIR} ${PREFIX}/include/GL/
	${INSTALL_DATA} ${WRKSRC}/include/GL/glu*.h ${PREFIX}/include/GL/

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.include <bsd.port.pre.mk>

.if !(${ARCH} == "amd64" || ${ARCH} == "i386")
CONFIGURE_ARGS+=--disable-gallium-intel
.endif

.include <bsd.port.post.mk>
