# New ports collection makefile for:    Mesa
# Version required:     2.4
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.19 1997/09/30 19:21:40 max Exp $
#

DISTNAME=       MesaLib-2.4
PKGNAME=	Mesa-2.4
CATEGORIES=	graphics
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/

MAINTAINER=	jseger@FreeBSD.ORG
WRKSRC=		${WRKDIR}/${PKGNAME}

ALL_TARGET=	freebsd
USE_X11=	yes
LIBS=		libMesaGL libMesaGLU
SHLIB_VERSION=	13.4

do-install:
.for file in ${LIBS}
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.a ${PREFIX}/lib
	ranlib ${PREFIX}/lib/${file}.a
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.so.${SHLIB_VERSION} ${PREFIX}/lib
.endfor
.for file in GL GLU
	@ln -fs ${PREFIX}/lib/libMesa${file}.a ${PREFIX}/lib/lib${file}.a
	@ln -fs ${PREFIX}/lib/libMesa${file}.so.${SHLIB_VERSION} ${PREFIX}/lib/lib${file}.so.${SHLIB_VERSION}
.endfor
	@${MKDIR} ${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/* ${PREFIX}/include/GL
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
