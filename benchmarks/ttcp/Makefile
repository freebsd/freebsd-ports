# New ports collection makefile for: ttcp
# Date created:			Tue Jun  1 22:58:13 PDT 1999
# Whom:				mharo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ttcp
PORTVERSION=	1.12
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.sgi.com/sgi/src/ttcp/
DISTFILES=	ttcp.c ttcp.1 README

MAINTAINER=	mharo@FreeBSD.org

EXTRACT_ONLY=	#none
NO_WRKSUBDIR=	yes
MAN1=		ttcp.1

post-extract:
	${CP} ${DISTDIR}/ttcp.c ${WRKSRC}/
	${CP} ${DISTDIR}/ttcp.1 ${WRKSRC}/
	${CP} ${DISTDIR}/README ${WRKSRC}/

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/ttcp ${WRKSRC}/ttcp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttcp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttcp.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/ttcp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ttcp/

.include <bsd.port.mk>
