# New ports collection makefile for:	fluctuate
# Date created:		6 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fluctuate
PORTVERSION=	1.40
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/lamarc/fluctuate/
DISTNAME=	${PORTNAME}1.4.src.doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to fit population models

WRKSRC=		${WRKDIR}/${PORTNAME}1.4
ALL_TARGET=	${PORTNAME}

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/*.doc ${DOCSDIR}/
.endif

.include <bsd.port.mk>
