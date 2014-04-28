# Created by: is grammatically incorrect in this context.
# $FreeBSD$

PORTNAME=	ptmalloc2
PORTVERSION=	20060605
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.malloc.de/malloc/
DISTNAME=	${PORTNAME}-current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative threads-aware malloc

USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}
USES=		gmake
ALL_TARGET=	posix

INCDIR=	include/${PORTNAME}
PLIST_SUB=	INCDIR=${INCDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/malloc.h ${STAGEDIR}${PREFIX}/${INCDIR}/
	${INSTALL_DATA} ${WRKSRC}/libmalloc.a ${STAGEDIR}${PREFIX}/lib/libptmalloc2.a
	${INSTALL_DATA} ${WRKSRC}/malloc.so ${STAGEDIR}${PREFIX}/lib/libptmalloc2.so.0
	${LN} -s libptmalloc2.so.0 ${STAGEDIR}${PREFIX}/lib/libptmalloc2.so

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
