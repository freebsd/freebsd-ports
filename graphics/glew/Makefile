# New ports collection makefile for: glew
# Date created:		29 Dec 2003
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	glew
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	mva@FreeBSD.org
COMMENT=	The OpenGL Extension Wrangler Library

USE_XORG=	x11 xext xi xmu
USE_GMAKE=	yes
USE_GL=		yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/glewinfo ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/visualinfo ${PREFIX}/bin

	${INSTALL_PROGRAM} ${WRKSRC}/lib/libGLEW.so.${PORTVERSION} \
		${PREFIX}/lib/libGLEW.so.1
	${LN} -sf ${PREFIX}/lib/libGLEW.so.1 ${PREFIX}/lib/libGLEW.so
	${INSTALL_DATA} ${WRKSRC}/lib/libGLEW.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/GL/*.h ${PREFIX}/include/GL

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in css html jpg png
	${INSTALL_DATA} ${WRKSRC}/doc/*.${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
