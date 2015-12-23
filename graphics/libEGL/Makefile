# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	libEGL
PORTVERSION=	${MESAVERSION}
PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	OpenEGL library

LIB_DEPENDS+=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libdevq.so:${PORTSDIR}/devel/libdevq \
		libdrm.so:${PORTSDIR}/graphics/libdrm

USE_GL=		gbm
USE_XORG=	x11 xau xcb xdmcp

# stuff not needed by libEGL but configure wants it
USE_XORG+=	glproto dri2proto xext xdamage xfixes presentproto \
		xshmfence

.include <bsd.port.options.mk>
.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

MESA_BUILD_WRKSRC=	src/mapi src/gbm src/egl/
MESA_INSTALL_WRKSRC=	src/egl

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/.mesa
	@${MV} ${STAGEDIR}${PREFIX}/lib/libEGL* \
		${STAGEDIR}${PREFIX}/lib/.mesa/

.include <bsd.port.mk>
