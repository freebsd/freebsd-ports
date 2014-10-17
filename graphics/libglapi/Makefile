# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglapi
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${LIBGLAPI_REVISION}
CATEGORIES=	graphics

COMMENT=	Common GL api library used by Mesa based ports

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libglapi but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes presentproto \
		xshmfence
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdrm.so:${PORTSDIR}/graphics/libdrm

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.if defined (WITH_NEW_MESA)
LIBGLAPI_REVISION=	0
.else
LIBGLAPI_REVISION=	2
.endif

.if defined (WITH_NEW_MESA)
BUILD_WRKSRC=	${WRKSRC}/src/mapi
INSTALL_WRKSRC=	${WRKSRC}/src/mapi
.else
BUILD_WRKSRC=	${WRKSRC}/src/mapi/shared-glapi
INSTALL_WRKSRC=	${WRKSRC}/src/mapi/shared-glapi
.endif

.include <bsd.port.mk>
