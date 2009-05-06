# Ports Collection Makefile for:	ptmalloc
# Date created:				10 December 2004
# Who:					Greg 'groggy' Lehey <grog@FreeBSD.org>
# Whom: is grammatically incorrect in this context.
#
# $FreeBSD$

PORTNAME=	ptmalloc
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.malloc.de/malloc/
DISTNAME=	${PORTNAME}3-current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative threads-aware malloc

USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}3

USE_GMAKE=	yes
ALL_TARGET=	posix

INCDIR=	include/${PORTNAME}
PLIST_SUB=	INCDIR=${INCDIR}

post-patch:
	@${REINPLACE_CMD} -e 's+-pthread+${PTHREAD_LIBS}+g ;'   \
		${WRKSRC}/Makefile

do-install:	all
	${MKDIR} ${PREFIX}/${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/malloc-2.8.3.h ${PREFIX}/${INCDIR}/malloc.h
	${INSTALL_DATA} ${WRKSRC}/libptmalloc3.a ${PREFIX}/lib/libptmalloc.a
	${INSTALL_DATA} ${WRKSRC}/ptmalloc3.so ${PREFIX}/lib/libptmalloc.so.3
	${LN} -s ${PREFIX}/lib/libptmalloc.so.3 ${PREFIX}/lib/libptmalloc.so

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		hangs while building on sparc64
.endif

.include <bsd.port.post.mk>
