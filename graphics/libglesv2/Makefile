# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglesv2
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL ES v2 library

LIB_DEPENDS+=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libexpat.so:${PORTSDIR}/textproc/expat2

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
