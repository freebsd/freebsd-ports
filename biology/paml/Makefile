# New ports collection makefile for:	paml
# Date created:				7 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	paml
PORTVERSION=	3.1
CATEGORIES=	biology
MASTER_SITES=	ftp://abacus.gene.ucl.ac.uk/pub/paml/
DISTNAME=	paml3.1
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dbader@eece.unm.edu

WRKSRC=		${WRKDIR}/${DISTNAME}/src

BINARIES=	baseml basemlg chi2 codeml codemlsites evolver mcmctree \
		pamp yn00

do-install:
.for f in ${BINARIES}
		${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/pamlDOC.pdf \
			${DOCSDIR}
.endif

.include <bsd.port.mk>
