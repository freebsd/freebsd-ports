# New ports collection makefile for:    Mesa
# Version required:     2.2
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.18 1997/09/30 19:20:00 max Exp $
#

DISTNAME=       Mesa-2.2
CATEGORIES=	graphics
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/

MAINTAINER=	ports@FreeBSD.ORG

ALL_TARGET=	freebsd
USE_X11=	yes
LIBS=		libMesaGL libMesaGLU libMesaaux libMesatk
SHLIB_VERSION=	13.2

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
	@${MKDIR} ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/samples ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/demos ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/book ${PREFIX}/share/examples/Mesa
	${CP} -Rp ${WRKSRC}/widgets-sgi ${PREFIX}/share/examples/Mesa
	@${RM} -f ${PREFIX}/share/examples/Mesa/widgets-sgi/Makefile~
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
