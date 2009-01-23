# New ports collection makefile for:    libglut
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 anholt
#
# $FreeBSD$
#

PORTNAME=	libglut
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	OpenGL utility toolkit

USE_LDCONFIG=	yes
USE_GL=		glu
USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes xi xmu

do-install:
	cd ${WRKSRC}/src/glut/glx; ${GMAKE} install

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
