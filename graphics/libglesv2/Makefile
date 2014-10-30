# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libglesv2
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${LIBGLES_REVISION}
CATEGORIES=	graphics

COMMENT=	OpenGL ES v2 library

LIB_DEPENDS+=	libdrm.so:${PORTSDIR}/graphics/libdrm \
		libglapi.so:${PORTSDIR}/graphics/libglapi \
		libexpat.so:${PORTSDIR}/textproc/expat2

# stuff not needed by libglesv2 but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes presentproto \
		xshmfence

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.if defined(WITH_NEW_MESA)
LIBGLES_REVISION=	3
.else
LIBGLES_REVISION=	3
.endif

.if defined(WITH_NEW_MESA)
BUILD_WRKSRC=	${WRKSRC}/src/mapi
INSTALL_WRKSRC=	${WRKSRC}/src/mapi
.else
BUILD_WRKSRC=	${WRKSRC}/src/mapi/es2api
INSTALL_WRKSRC=	${WRKSRC}/src/mapi/es2api
.endif

.if !defined(WITH_NEW_MESA)
pre-build:
	@cd ${WRKSRC}/src/mapi/shared-glapi && ${MAKE_CMD} ${_MAKE_JOBS}
.else
post-install:
	@${RM} ${STAGEDIR}/${PREFIX}/lib/libglapi*
.endif

.include <bsd.port.mk>
