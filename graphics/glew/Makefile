# New ports collection makefile for: glew
# Date created:		29 Dec 2003
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	glew
PORTVERSION=	1.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	The OpenGL Extension Wrangler Library

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	"CC=${CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/glewinfo ${PREFIX}/bin

	${INSTALL_PROGRAM} ${WRKSRC}/lib/libGLEW.so.${PORTVERSION} \
		${PREFIX}/lib/libGLEW.so.1
	@${LN} -sf ${PREFIX}/lib/libGLEW.so.1 ${PREFIX}/lib/libGLEW.so
	${INSTALL_DATA} ${WRKSRC}/lib/libGLEW.a ${PREFIX}/lib

.for i in glew glxew
	${INSTALL_DATA} ${WRKSRC}/include/GL/${i}.h ${PREFIX}/include/GL
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/glew.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/glew.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
