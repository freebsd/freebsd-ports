# New ports collection makefile for:    libGLw
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libGLw
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL widgets library

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS+=	Xm.3:${PORTSDIR}/x11-toolkits/open-motif

USE_GL=		gl
USE_XORG=	xt

CFLAGS+=	-D__GLX_MOTIF=1
SRCDIR=		glw

HEADERS=	GLwDrawA.h GLwDrawAP.h GLwMDrawA.h GLwMDrawAP.h
HEADERSDIR=	src/glw

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
