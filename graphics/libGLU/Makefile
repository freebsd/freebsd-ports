# New ports collection makefile for:    libGLU
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libGLU
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/
DISTNAME=	X11R6.7.0-src1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL utility library

LIB_DEPENDS=	GL.1:${PORTSDIR}/x11/libGL

CONFLICTS=	XFree86-libraries-*

EXTRA_PATCHES=	${CF_PATCHES}

XBUILD_DIRS=	lib/GLU
INSTALLS_SHLIB=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/GL/glu.h ${PREFIX}/include/GL

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.mk>
