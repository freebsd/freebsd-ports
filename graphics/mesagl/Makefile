# New ports collection makefile for:    Mesa
# Version required:     3.0
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $FreeBSD$
#

DISTNAME=       MesaLib-3.0
PKGNAME=	Mesa-3.0
CATEGORIES=	graphics
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/ \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} MesaDemos-3.0.tar.gz

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=		${WRKDIR}/Mesa-3.0

USE_X_PREFIX=	yes
LIBS=		libMesaGL libMesaGLU

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
ALL_TARGET=	freebsd-elf
SHLIB_VERSION=	14
GLUT_VERSION=	3
.else
ALL_TARGET=	freebsd
SHLIB_VERSION=	14.0
GLUT_VERSION=	3.7
.endif

do-install:
.for file in ${LIBS}
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/${file}.so.${SHLIB_VERSION} ${PREFIX}/lib
	${LN} -fs ${file}.so.${SHLIB_VERSION} ${PREFIX}/lib/${file}.so
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/libglut.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libglut.so.${GLUT_VERSION} ${PREFIX}/lib
	${LN} -fs libglut.so.${GLUT_VERSION} ${PREFIX}/lib/libglut.so
.for file in GL GLU
	@${LN} -fs libMesa${file}.a ${PREFIX}/lib/lib${file}.a
	@${LN} -fs libMesa${file}.so.${SHLIB_VERSION} ${PREFIX}/lib/lib${file}.so.${SHLIB_VERSION}
	@${LN} -fs libMesa${file}.so ${PREFIX}/lib/lib${file}.so
.endfor
	@${MKDIR} ${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/* ${PREFIX}/include/GL
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
