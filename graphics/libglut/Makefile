# New ports collection makefile for:    libglut
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 anholt
#
# $FreeBSD$
#

PORTNAME=	libglut
PORTVERSION=	5.0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mesa3d
DISTNAME=	MesaDemos-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphics library similar to SGI's OpenGL

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_GL=		yes

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}/src-glut

pre-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

.include <bsd.port.mk>
