# New ports collection makefile for:	xmill
# Date created:				09 May 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	xmill
PORTVERSION=	0.7
CATEGORIES=	archivers
MASTER_SITES=	http://www.research.att.com/~mff/XMILL/
DISTNAME=	xmill-0-7

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An efficient compressor for XML

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile

USE_ZIP=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="Explicit agreement to the terms and conditions of the license required.  Download ${DISTNAME}${EXTRACT_SUFX} manually from http://www.research.att.com/sw/tools/xmill/download.html, put it under ${DISTDIR} and run make again"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xmill ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xdemill ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xbmill ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xbdemill ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/paper/xmill.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
