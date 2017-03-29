# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglapi
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	Common GL api library used by Mesa based ports

LICENSE=	MIT

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs

USE_XORG=	x11 xau xcb xdmcp xvmc

# stuff not needed by libglapi but configure wants it
USE_XORG+=	dri2proto dri3proto glproto presentproto xdamage xext xfixes \
		xshmfence
LIB_DEPENDS+=	libexpat.so:textproc/expat2 \
		libdrm.so:graphics/libdrm

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

MESA_BUILD_WRKSRC=	src/mapi
MESA_INSTALL_WRKSRC=	src/mapi

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/include/GLES*
	@${RM} ${STAGEDIR}${PREFIX}/lib/libGLESv2.so*
	@${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/glesv2.pc

.include <bsd.port.mk>
