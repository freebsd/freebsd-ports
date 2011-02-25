# New ports collection makefile for:    libGLU
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libGLU
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL utility library

USE_GL=		gl
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

do-install:
	cd ${WRKSRC}/src/glu; ${GMAKE} install
	${INSTALL_DATA} ${WRKSRC}/include/GL/glu*.h ${PREFIX}/include/GL/
	cd ${WRKSRC}/src/glu; ${GMAKE} install

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
