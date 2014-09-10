# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglesv2
PORTVERSION=	${MESAVERSION}
PORTREVISION=	2
CATEGORIES=	graphics

COMMENT=	OpenGL ES v2 library

BUILD_DEPENDS=	expat>=0:${PORTSDIR}/textproc/expat2
LIB_DEPENDS+=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libglapi.so:${PORTSDIR}/graphics/libglapi

.include <bsd.port.options.mk>

.if ! defined(WITH_NEW_XORG)
IGNORE=		Please enable WITH_NEW_XORG, libglesv2 needs libdrm higher then 2.4.24
.endif

# stuff not needed by libEGL but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes


BUILD_WKRSRC=	${WRKSRC}/src/mapi/es2api
INSTALL_WRKSRC=	${WRKSRC}/src/mapi/es2api

# this library doesn't exist in Mesa 7.6 so use newer
WITH_NEW_XORG=yes

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
