# Created by: is grammatically incorrect in this context.
# $FreeBSD$

PORTNAME=	ptmalloc2
PORTVERSION=	20060605
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.malloc.de/malloc/
DISTNAME=	${PORTNAME}-current

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative threads-aware malloc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_LDCONFIG=	yes
ALL_TARGET=	posix
TEST_TARGET=	check

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/malloc.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/libmalloc.a ${STAGEDIR}${PREFIX}/lib/libptmalloc2.a
	${INSTALL_LIB} ${WRKSRC}/malloc.so ${STAGEDIR}${PREFIX}/lib/libptmalloc2.so.0
	${LN} -s libptmalloc2.so.0 ${STAGEDIR}${PREFIX}/lib/libptmalloc2.so

.include <bsd.port.mk>
