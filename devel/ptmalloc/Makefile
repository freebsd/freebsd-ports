# Created by: is grammatically incorrect in this context.
# $FreeBSD$

PORTNAME=	ptmalloc
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.malloc.de/malloc/
DISTNAME=	${PORTNAME}3-current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative threads-aware malloc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}3

USES=		gmake
ALL_TARGET=	posix

INCDIR=		include/${PORTNAME}
PLIST_SUB=	INCDIR=${INCDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/malloc-2.8.3.h ${STAGEDIR}${PREFIX}/${INCDIR}/malloc.h
	${INSTALL_DATA} ${WRKSRC}/libptmalloc3.a ${STAGEDIR}${PREFIX}/lib/libptmalloc.a
	${INSTALL_LIB} ${WRKSRC}/ptmalloc3.so ${STAGEDIR}${PREFIX}/lib/libptmalloc.so.3
	${LN} -sf libptmalloc.so.3 ${STAGEDIR}${PREFIX}/lib/libptmalloc.so

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
