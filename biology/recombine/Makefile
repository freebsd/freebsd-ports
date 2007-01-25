# New ports collection makefile for:	recombine
# Date created:		6 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	recombine
PORTVERSION=	1.41
CATEGORIES=	biology
MASTER_SITES=	http://evolution.gs.washington.edu/lamarc/recombine/
DISTNAME=	${PORTNAME}${PORTVERSION}.src.doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to fit population models across sites

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/filetran ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/recombine.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
