# New ports collection makefile for:    Mesa
# Version required:     2.6
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.21 1997/11/22 02:05:20 jseger Exp $
#

DISTNAME=       MesaLib-2.6
PKGNAME=	Mesa-2.6
CATEGORIES=	graphics
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/

MAINTAINER=	jseger@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${PKGNAME}

ALL_TARGET=	freebsd
USE_X11=	yes
LIBS=		libMesaGL libMesaGLU
SHLIB_VERSION=	13.6

do-install:
.for file in ${LIBS}
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.so.${SHLIB_VERSION} ${PREFIX}/lib
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/libglut.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libglut.so.3.6 ${PREFIX}/lib
.for file in GL GLU
	@ln -fs ${PREFIX}/lib/libMesa${file}.a ${PREFIX}/lib/lib${file}.a
	@ln -fs ${PREFIX}/lib/libMesa${file}.so.${SHLIB_VERSION} ${PREFIX}/lib/lib${file}.so.${SHLIB_VERSION}
.endfor
	@${MKDIR} ${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/* ${PREFIX}/include/GL
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
