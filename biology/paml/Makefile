# Created by: dbader@eece.unm.edu
# $FreeBSD$

PORTNAME=	paml
PORTVERSION=	4.9c
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://abacus.gene.ucl.ac.uk/software/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Phylogenetic Analysis by Maximum Likelihood (PAML)

LICENSE=	GPLv3

USES=		gmake tar:tgz

BINARIES=	baseml basemlg chi2 codeml evolver evolverNSbranches \
		evolverNSbranchsites evolverNSsites pamp yn00

PORTDOCS=	MCMCtree.Tutorials.pdf MCMCtreeDOC.pdf pamlDOC.pdf pamlFAQs.pdf \
		pamlHistory.txt README.txt

DATA=		3s.trees 4s.trees 5s.trees 6s.trees GeneticCode.txt MCaa.dat	\
		MCbase.dat MCbaseRandomTree.dat MCcodon.dat aaml.ctl baseml.ctl	\
		brown.nuc brown.rooted.trees brown.trees codeml.ctl codonml.ctl	\
		mcmctree.ctl pamp.ctl paupblock paupend paupstart stewart.aa	\
		stewart.trees yn00.ctl
PORTDATA=	${DATA} dat examples Technical

OPTIONS_DEFINE=	DOCS

# Remove Windows executables
post-extract:
	@${FIND} ${WRKSRC}/Technical -name "*.exe" -delete

do-build:
	@cd ${WRKSRC}/src && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD}
.for f in NSbranches NSsites NSbranchsites
	@cd ${WRKSRC}/src && \
	${CC} ${CFLAGS} -DCodon${f} -o evolver${f} evolver.c tools.c -lm
.endfor

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${DATA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DATADIR}
.endfor
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "dat examples Technical" \
	${STAGEDIR}/${DATADIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
