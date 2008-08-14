# Ports Collection Makefile for:	ptmalloc
# Date created:				10 December 2004
# Who:					Greg 'groggy' Lehey <grog@FreeBSD.org>
# Whom: is grammatically incorrect in this context.
#
# $FreeBSD$

PORTNAME=	ptmalloc
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.malloc.de/malloc/
DISTNAME=	${PORTNAME}2-current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative threads-aware malloc

USE_GMAKE=	yes
USE_LD_CONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}2
INCDIR=	include/${PORTNAME}

PLIST_SUB=	INCDIR=${INCDIR}

post-patch:
	@${REINPLACE_CMD} -e 's+-pthread+${PTHREAD_LIBS}+g ;'   \
		${WRKSRC}/Makefile

do-install:	all
	${MKDIR} ${PREFIX}/${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/malloc.h ${PREFIX}/${INCDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/malloc.so ${PREFIX}/lib/libptmalloc.so.2
	${LN} -s ${PREFIX}/lib/ptmalloc.so.2 ${PREFIX}/lib/libptmalloc.so
	${INSTALL_PROGRAM} ${WRKSRC}/libmalloc.a ${PREFIX}/lib/libptmalloc.a

post-install:
	@${ECHO_CMD}
	@${ECHO_CMD} Not much documentation is available.
	@${ECHO_CMD} Read ${WRKSRC:S|^${WRKDIRPREFIX}${.CURDIR}/||}/README for what there is.
	@${ECHO_CMD} See also pkg_descr
	@${ECHO_CMD}

.include <bsd.port.mk>
