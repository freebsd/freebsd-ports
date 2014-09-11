# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglapi
PORTVERSION=	${MESAVERSION}
PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	Common GL api library used by Mesa based ports

BUILD_DEPENDS=	expat>=0:${PORTSDIR}/textproc/expat2 \
		libdrm>=0:${PORTSDIR}/graphics/libdrm \
		libpthread-stubs>=0:${PORTSDIR}/devel/libpthread-stubs

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libglapi but configure wants it
USE_XORG+=	glproto dri2proto dri3proto xext xdamage xfixes presentproto \
		xshmfence

BUILD_WRKSRC=	${WRKSRC}/src/mapi/shared-glapi
INSTALL_WRKSRC=	${WRKSRC}/src/mapi/shared-glapi

.include <bsd.port.options.mk>

.if ! defined(WITH_NEW_XORG)
IGNORE=	Please enable WITH_NEW_XORG, libglapi needs libdrm higher then 2.4.24
.endif

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
