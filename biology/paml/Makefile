PORTNAME=	paml
DISTVERSION=	4.10.7
CATEGORIES=	biology

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Phylogenetic Analysis by Maximum Likelihood (PAML)
WWW=		http://abacus.gene.ucl.ac.uk/software/paml.html

LICENSE=	GPLv3

USES=		dos2unix gmake
DOS2UNIX_GLOB=	*.aa *.c *.ctl *.dat *.HKYG5 *.nexus *.nuc *.phy *.result *.tre \
		*.trees *.txt *.xml paupblock paupend
USE_GITHUB=	yes
GH_ACCOUNT=	abacus-gene

BINARIES=	baseml basemlg chi2 codeml evolver evolverNSbranches \
		evolverNSbranchsites evolverNSsites infinitesites mcmctree pamp \
		yn00

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${FIND} ${WRKSRC}/Technical -name "*.exe" -delete

do-build:
	@cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}
.for f in NSbranches NSsites NSbranchsites
	@cd ${WRKSRC}/src && \
	${CC} ${CFLAGS} -DCodon${f} -o evolver${f} evolver.c tools.c -lm
.endfor

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "dat Technical" \
		${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
