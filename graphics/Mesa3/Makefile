# New ports collection makefile for:    Mesa
# Version required:     2.6
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.23 1998/03/10 09:26:05 tg Exp $
#

DISTNAME=       MesaLib-2.6
PKGNAME=	Mesa-2.6
CATEGORIES=	graphics
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} MesaDemos-2.6.tar.gz

MAINTAINER=	jseger@FreeBSD.ORG

BROKEN=		awaiting upgrade to Mesa3 after repository copy

WRKSRC=		${WRKDIR}/${PKGNAME}

ALL_TARGET=	freebsd-386
USE_X11=	yes
LIBS=		libMesaGL libMesaGLU libMesaaux libMesatk
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
	${INSTALL_DATA} ${WRKSRC}/include/glaux.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/gltk.h ${PREFIX}/include
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
