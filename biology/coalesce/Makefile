# New ports collection makefile for:	coalesce
# Date created:		6 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	coalesce
PORTVERSION=	1.50
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/lamarc/coalesce/
DISTNAME=	${PORTNAME}1.5b
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to fit population models

NO_WRKSUBDIR=	yes
ALL_TARGET=	${PORTNAME}

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/*.doc ${DOCSDIR}/
.endif

.include <bsd.port.mk>
