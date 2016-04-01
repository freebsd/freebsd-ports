# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglesv2
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	OpenGL ES v2 library

LIB_DEPENDS+=	libdrm.so:graphics/libdrm \
		libglapi.so:graphics/libglapi \
		libexpat.so:textproc/expat2

# stuff not needed by libglesv2 but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes presentproto \
		xshmfence

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

BUILD_WRKSRC=	${WRKSRC}/src/mapi
INSTALL_WRKSRC=	${WRKSRC}/src/mapi

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/.mesa
	@${MV} ${STAGEDIR}${PREFIX}/lib/libGLESv2.so* \
		${STAGEDIR}${PREFIX}/lib/.mesa/

.include <bsd.port.mk>
