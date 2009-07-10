# New ports collection makefile for: glfw
# Date created:		24 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	glfw
PORTVERSION=	2.6
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable framework for OpenGL development

USE_BZIP2=	yes
USE_XORG=	x11 xxf86vm xext xrandr
USE_GL=		yes
USE_LDCONFIG=	yes
ALL_TARGET=	x11
INSTALL_TARGET=	x11-install
MAKE_JOBS_UNSAFE=yes
WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|' ${WRKSRC}/compile.sh

do-configure:
	@(cd ${WRKSRC} &&		\
	${SETENV} CC="${CC}"		\
		  CFLAGS="${CFLAGS}"	\
		  PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}" ${SH} compile.sh)

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/x11/libglfw.so ${PREFIX}/lib/libglfw.so.0
	${LN} -sf ${PREFIX}/lib/libglfw.so.0 ${PREFIX}/lib/libglfw.so
.ifndef (NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile.x11 ${EXAMPLESDIR}/makefile
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.tga ${EXAMPLESDIR}
.endif
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
