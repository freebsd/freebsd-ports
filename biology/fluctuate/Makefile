# New ports collection makefile for:	fluctuate
# Date created:		6 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fluctuate
PORTVERSION=	1.30
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/lamarc/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	wjv@FreeBSD.org

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
