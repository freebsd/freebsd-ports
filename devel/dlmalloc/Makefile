# New ports collection makefile for:	dlmalloc
# Date created:				4 April 2001
# Whom:					Maxim Sobolax <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dlmalloc
PORTVERSION=	2.7.0
CATEGORIES=	devel
MASTER_SITES=	ftp://gee.cs.oswego.edu/pub/misc/
DISTFILES=	malloc-${PORTVERSION}.c malloc-${PORTVERSION}.h
EXTRACT_ONLY=

MAINTAINER=	sobomax@FreeBSD.org

DIST_SUBDIR=	${PORTNAME}
WRKSRC=		${WRKDIR}
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PKGMESSAGE=	${WRKDIR}/pkg-message

do-extract:
	@${MKDIR} ${WRKDIR}
.for file in ${DISTFILES}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} \
		${WRKSRC}/${file:S/-${PORTVERSION}//}
.endfor

do-install:
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	${MKDIR} ${PREFIX}/share/doc/dlmalloc
	${INSTALL_DATA} ${WRKSRC}/malloc.h ${PREFIX}/include/${PORTNAME}
.for suffix in "" # "_r" <- thread-safe version doesn't work yet
	${INSTALL_DATA} ${WRKSRC}/libdlmalloc${suffix}.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/dlmalloc_module${suffix}.so ${PREFIX}/lib
.endfor
	${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/README.FreeBSD | \
		/usr/bin/fmt > ${WRKDIR}/README.FreeBSD
	${INSTALL_MAN} ${WRKDIR}/README.FreeBSD ${PREFIX}/share/doc/dlmalloc
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message | \
		/usr/bin/fmt > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
