# New ports collection makefile for:	paml
# Date created:				7 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	paml
PORTVERSION=	3.14
CATEGORIES=	biology
MASTER_SITES=	ftp://abacus.gene.ucl.ac.uk/pub/paml/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	dbader@eece.unm.edu
COMMENT=	Phylogenetic Analysis by Maximum Likelihood (PAML)

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

BINARIES=	baseml basemlg chi2 codeml evolver pamp yn00

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
