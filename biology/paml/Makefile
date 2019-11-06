# Created by: dbader@eece.unm.edu
# $FreeBSD$

PORTNAME=	paml
PORTVERSION=	4.9i
CATEGORIES=	biology
MASTER_SITES=	http://abacus.gene.ucl.ac.uk/software/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Phylogenetic Analysis by Maximum Likelihood (PAML)

BROKEN=		unfetchable

LICENSE=	GPLv3

USES=		dos2unix gmake tar:tgz

DOS2UNIX_GLOB=	*.HKYG5 *.aa *.c *.ctl *.dat *.nexus *.nuc *.phy *.result *.tre \
		*.trees *.txt *.xml paupblock paupend

BINARIES=	baseml basemlg chi2 codeml evolver evolverNSbranches \
		evolverNSbranchsites evolverNSsites pamp yn00

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
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "dat Technical" \
		${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.for f in *.aa *.ctl *.dat *.nuc *.trees *.txt paup*
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
