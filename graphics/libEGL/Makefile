# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libEGL
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenEGL library

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs

.if ! defined(WITH_NEW_XORG)
IGNORE=		Please enable WITH_NEW_XORG, libEGL needs libdrm higher then 2.4.24
.endif

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libEGL but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdrm.so:${PORTSDIR}/graphics/libdrm

BUILD_WRKSRC=	${WRKSRC}/src/egl
INSTALL_WRKSRC=	${WRKSRC}/src/egl

WITH_NEW_XORG=	yes

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
