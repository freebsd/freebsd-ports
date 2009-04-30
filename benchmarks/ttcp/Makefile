# New ports collection makefile for: ttcp
# Date created:			Tue Jun  1 22:58:13 PDT 1999
# Whom:				mharo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ttcp
PORTVERSION=	1.12
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.sgi.com/sgi/src/ttcp/
DISTFILES=	ttcp.c ttcp.1 README
EXTRACT_ONLY=	#none

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Benchmarking tool for analysing TCP and UDP performance

NO_WRKSUBDIR=	yes
DIST_SUBDIR=	${PORTNAME}
MAN1=		ttcp.1

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ttcp.c ${WRKSRC}/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ttcp.1 ${WRKSRC}/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/README ${WRKSRC}/

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/ttcp ${WRKSRC}/ttcp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttcp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttcp.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/ttcp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ttcp/

.include <bsd.port.mk>
