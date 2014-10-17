# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	gbm
PORTVERSION=	${MESAVERSION}
PORTREVISION=	${GBM_REVISION}
CATEGORIES=	graphics

COMMENT=	gbm library

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdrm.so:${PORTSDIR}/graphics/libdrm \
		libglapi.so:${PORTSDIR}/graphics/libglapi

USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by gbm but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes presentproto \
		xshmfence

BUILD_WRKSRC=	${WRKSRC}/src/gbm
INSTALL_WRKSRC=	${WRKSRC}/src/gbm

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"

.if defined(WITH_NEW_MESA)
GBM_REVISION=	0
.else
GBM_REVISION=	0
.endif

pre-build:
.if defined(WITH_NEW_MESA)
	@cd ${WRKSRC}/src/mapi/ && ${MAKE_CMD} ${_MAKE_JOBS}
.else
	@cd ${WRKSRC}/src/mapi/shared-glapi && ${MAKE_CMD} ${_MAKE_JOBS}
.endif

.include <bsd.port.mk>
