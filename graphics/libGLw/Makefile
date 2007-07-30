# New ports collection makefile for:    libGLw
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libGLw
PORTVERSION=	6.5.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	 mesa3d
DISTNAME=	MesaLib-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL widgets library

CONFLICTS=	XFree86-libraries-* xorg-libraries-6.*

LIB_DEPENDS+=	Xm.3:${PORTSDIR}/x11-toolkits/open-motif

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_XORG=	xt
USE_GL=		gl

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}/src/glw/

ALL_TARGET=	libGLw.so
GLWHEADERS=	GLwDrawA.h GLwDrawAP.h GLwMDrawA.h GLwMDrawAP.h

post-patch:
	${CP} ${FILESDIR}/config ${WRKDIR}/Mesa-${PORTVERSION}/configs/current

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libGLw.so.1 ${PREFIX}/lib
	${LN} -sf libGLw.so.1 ${PREFIX}/lib/libGLw.so
.for i in ${GLWHEADERS}
	${INSTALL_DATA} ${WRKDIR}/Mesa-${PORTVERSION}/src/glw/$i ${PREFIX}/include/GL
.endfor

.include <bsd.port.mk>
