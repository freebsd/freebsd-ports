# Ports Collection Makefile for:	ptmalloc
# Date created:				10 December 2004
# Who:					Greg 'groggy' Lehey <grog@FreeBSD.org>
# Whom: is grammatically incorrect in this context.
#
# $FreeBSD$

PORTNAME=	ptmalloc
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.malloc.de/malloc/
DISTNAME=	ptmalloc

MAINTAINER=	grog@FreeBSD.org
COMMENT=	Alternative malloc, performs better with threaded applications

do-install:	all
	${INSTALL_PROGRAM} ${WRKSRC}/ptmalloc.so ${PREFIX}/lib/libptmalloc.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/ptmalloc.so ${PREFIX}/lib/libptmalloc.so
	${INSTALL_PROGRAM} ${WRKSRC}/libptmalloc.a ${PREFIX}/lib/libptmalloc.a

post-install:
	@${ECHO_CMD}
	@${ECHO_CMD} Not much documentation is available.
	@${ECHO_CMD} Read work/ptmalloc/README for what there is.
	@${ECHO_CMD} See also pkg_descr
	@${ECHO_CMD}

.include <bsd.port.mk>
