# $FreeBSD$

PORTNAME=	pixz
PORTVERSION=	1.0.2
CATEGORIES=	archivers
MASTER_SITES=	SF/pixz
EXTRACT_SUFX=	.tgz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Parallel, indexing version of XZ

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

SUB_FILES=	Makefile
PLIST_FILES=	bin/${PORTNAME} man/man1/pixz.1.gz
USES=		uidfix
MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}

post-extract: apply-slist
	${INSTALL_DATA} ${WRKDIR}/Makefile ${WRKSRC}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.1 ${WRKSRC}

.include <bsd.port.mk>
