# New ports collection makefile for: glfw
# Date created:		24 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	glfw
PORTVERSION=	2.4.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	A portable framework for OpenGL development

USE_X_PREFIX=	yes
USE_GL=		yes
ALL_TARGET=	x11

do-configure:
	@(cd ${WRKSRC} &&		\
	${SETENV} CC="${CC}"		\
		  CFLAGS="${CFLAGS}"	\
		  X11BASE="${X11BASE}"	\
		  PTHREAD_LIBS="${PTHREAD_LIBS}" ./compile.sh)

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/x11/libglfw.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/GL/glfw.h ${PREFIX}/include/GL

	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile.x11 ${EXAMPLESDIR}/makefile
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.tga ${EXAMPLESDIR}

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
