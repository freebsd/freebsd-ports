# New ports collection makefile for:   as80
# Date created:        02 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	as80
PORTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	http://home.t-online.de/home/thomas.strathmann/files/

MAINTAINER=	greid@ukug.uk.freebsd.org

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/as80 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/asm80 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/as80
	${INSTALL_DATA} ${WRKSRC}/Manual.txt ${PREFIX}/share/doc/as80
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/as80
.endif

.include <bsd.port.mk>
