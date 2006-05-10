# New ports collection makefile for:    libglut
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 anholt
#
# $FreeBSD$
#

PORTNAME=	libglut
PORTVERSION=	6.4.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mesa3d
DISTNAME=	MesaGLUT-${PORTVERSION}

MAINTAINER=	shaun@inerd.com
COMMENT=	A graphics library similar to SGI's OpenGL

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_GL=		yes

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}/src/glut/glx

pre-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

pre-install:
	@${MKDIR} ${PREFIX}/include/GL

.include <bsd.port.mk>
