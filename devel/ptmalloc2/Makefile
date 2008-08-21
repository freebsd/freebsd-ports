# Ports Collection Makefile for:	ptmalloc
# Date created:				10 December 2004
# Who:					Greg 'groggy' Lehey <grog@FreeBSD.org>
# Whom: is grammatically incorrect in this context.
#
# $FreeBSD$

PORTNAME=	ptmalloc
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.malloc.de/malloc/
DISTNAME=	${PORTNAME}2-current

MAINTAINER=	giffunip@tutopia.com
COMMENT=	Alternative threads-aware malloc

USE_LD_CONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}2
ALL_TARGET=	posix

INCDIR=	include/${PORTNAME}
PLIST_SUB=	INCDIR=${INCDIR}

post-patch:
	@${REINPLACE_CMD} -e 's+-pthread+${PTHREAD_LIBS}+g ;'   \
		${WRKSRC}/Makefile

do-install:	all
	${MKDIR} ${PREFIX}/${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/malloc.h ${PREFIX}/${INCDIR}/
	${INSTALL_DATA} ${WRKSRC}/malloc.so ${PREFIX}/lib/libptmalloc.so.2
	${LN} -s ${PREFIX}/lib/ptmalloc.so.2 ${PREFIX}/lib/libptmalloc.so
	${INSTALL_DATA} ${WRKSRC}/libmalloc.a ${PREFIX}/lib/libptmalloc.a

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
