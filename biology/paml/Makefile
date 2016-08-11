# Created by: dbader@eece.unm.edu
# $FreeBSD$

PORTNAME=	paml
PORTVERSION=	4.9a
CATEGORIES=	biology
MASTER_SITES=	http://abacus.gene.ucl.ac.uk/software/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Phylogenetic Analysis by Maximum Likelihood (PAML)

USES=		gmake tar:tgz
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

BINARIES=	baseml basemlg chi2 codeml evolver pamp yn00
DOC_FILES=	pamlDOC.pdf pamlFAQs.pdf pamlHistory.txt

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/../doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
