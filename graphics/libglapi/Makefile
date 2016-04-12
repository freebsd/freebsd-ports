# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglapi
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	Common GL api library used by Mesa based ports

LIB_DEPENDS+=	libpthread-stubs.so:devel/libpthread-stubs

USE_XORG=	x11 xau xcb xdmcp xvmc

# stuff not needed by libglapi but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes presentproto \
		xshmfence
LIB_DEPENDS+=	libexpat.so:textproc/expat2 \
		libdrm.so:graphics/libdrm

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

MESA_BUILD_WRKSRC=	src/mapi
MESA_INSTALL_WRKSRC=	src/mapi

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/include/GLES*
	@${RM} -f ${STAGEDIR}${PREFIX}/lib/libGLESv2.so*
	@${RM} -f ${STAGEDIR}${PREFIX}/libdata/pkgconfig/glesv2.pc

.include <bsd.port.mk>
