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

USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}3
USE_LDCONFIG=	yes
ALL_TARGET=	posix
TEST_TARGET=	check

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/malloc-2.8.3.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/malloc.h
	${INSTALL_DATA} ${WRKSRC}/libptmalloc3.a ${STAGEDIR}${PREFIX}/lib/libptmalloc.a
	${INSTALL_LIB} ${WRKSRC}/ptmalloc3.so ${STAGEDIR}${PREFIX}/lib/libptmalloc.so.3
	${LN} -sf libptmalloc.so.3 ${STAGEDIR}${PREFIX}/lib/libptmalloc.so

.include <bsd.port.mk>
