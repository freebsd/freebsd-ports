# New ports collection makefile for:	recombine
# Date created:		6 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	recombine
PORTVERSION=	1.40
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/lamarc/recombine/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to fit population models across sites

DEPRECATED=	distfile disappeared from homepage
EXPIRATION_DATE=	2007-01-07

NO_WRKSUBDIR=	yes
ALL_TARGET=	${PORTNAME}

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@ ${INSTALL_SCRIPT} ${WRKSRC}/filetran ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/*.doc ${DOCSDIR}/
.endif

.include <bsd.port.mk>
