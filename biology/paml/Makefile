# Created by: dbader@eece.unm.edu
# $FreeBSD$

PORTNAME=	paml
PORTVERSION=	4.4c
CATEGORIES=	biology
MASTER_SITES=	http://abacus.gene.ucl.ac.uk/software/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Phylogenetic Analysis by Maximum Likelihood (PAML)

USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}44/src
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

BINARIES=	baseml basemlg chi2 codeml evolver pamp yn00
DOC_FILES=	MCMCtreeDoc.pdf pamlDOC.pdf pamlFAQs.pdf pamlHistory.txt

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}44/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
