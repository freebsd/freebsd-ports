# Ports Collection Makefile for:	ptmalloc
# Date created:				10 December 2004
# Who:					Greg 'groggy' Lehey <grog@FreeBSD.org>
# Whom: is grammatically incorrect in this context.
#
# $FreeBSD$

PORTNAME=	ptmalloc
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.malloc.de/malloc/
DISTNAME=	ptmalloc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative malloc, performs better with threaded applications

INCDIR=	include/${PORTNAME}

PLIST_SUB=	INCDIR=${INCDIR}

do-install:	all
	${MKDIR} ${PREFIX}/${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/ptmalloc.h ${PREFIX}/${INCDIR}/malloc.h
	${INSTALL_PROGRAM} ${WRKSRC}/ptmalloc.so ${PREFIX}/lib/libptmalloc.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/ptmalloc.so ${PREFIX}/lib/libptmalloc.so
	${INSTALL_PROGRAM} ${WRKSRC}/libptmalloc.a ${PREFIX}/lib/libptmalloc.a

post-install:
	@${ECHO_CMD}
	@${ECHO_CMD} Not much documentation is available.
	@${ECHO_CMD} Read ${WRKSRC:S|^${WRKDIRPREFIX}${.CURDIR}/||}/README for what there is.
	@${ECHO_CMD} See also pkg_descr
	@${ECHO_CMD}

.include <bsd.port.mk>
