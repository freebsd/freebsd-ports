# New ports collection makefile for:    Mesa
# Version required:     3.0 beta 6
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.24 1998/07/20 10:14:24 asami Exp $
#

DISTNAME=       MesaLib-3.0beta6
PKGNAME=	Mesa-3.0b6
CATEGORIES=	graphics
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/beta/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} MesaDemos-3.0beta6.tar.gz

MAINTAINER=	jseger@FreeBSD.ORG

WRKSRC=		${WRKDIR}/Mesa-3.0

ALL_TARGET=	freebsd
USE_X11=	yes
LIBS=		libMesaGL libMesaGLU
SHLIB_VERSION=	14.0
NO_LATEST_LINK=	yes

do-install:
.for file in ${LIBS}
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.so.${SHLIB_VERSION} ${PREFIX}/lib
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/libglut.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libglut.so.3.7 ${PREFIX}/lib
.for file in GL GLU
	@ln -fs ${PREFIX}/lib/libMesa${file}.a ${PREFIX}/lib/lib${file}.a
	@ln -fs ${PREFIX}/lib/libMesa${file}.so.${SHLIB_VERSION} ${PREFIX}/lib/lib${file}.so.${SHLIB_VERSION}
.endfor
	@${MKDIR} ${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/* ${PREFIX}/include/GL
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
