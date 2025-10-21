PORTNAME=	haplohseq
DISTVERSION=	0.1.2-3
PORTREVISION=	2
DISTVERSIONSUFFIX=	-gfeb9267
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify regions of allelic imbalance
WWW=		https://github.com/outpaddling/haplohseq \
		https://sites.google.com/site/integrativecancergenomics/software/haplohseq

LICENSE=	MIT

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
RUN_DEPENDS=	R-cran-optparse>0:devel/R-cran-optparse

USES=		compiler:c++14-lang gmake localbase:ldflags python
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

OPTIONS_DEFINE=	EXAMPLES

MAKEFILE=	makefile
CXXFLAGS+=	-std=c++14
LDFLAGS+=	-lpthread
MAKE_ENV=	STRIP=${STRIP}

SUB_FILES=	haplohseq-example

post-patch:
	@${REINPLACE_CMD} -e 's/-lboost_system //' ${WRKSRC}/makefile

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|/bin/sh|' \
		-e 's|python|mkdir example_output; ${PYTHON_CMD}|' \
		-e 's|\.\./haplohseq|haplohseq|' \
		${WRKSRC}/example/example_run.sh

post-install-EXAMPLES-on:
	${INSTALL_SCRIPT} ${WRKDIR}/haplohseq-example ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${RM} example/*.orig scripts/*.orig && ${COPYTREE_SHARE} "example ldmap scripts" ${STAGEDIR}${EXAMPLESDIR})

do-test:
	@(cd ${WRKSRC}/build/test && ${FILESDIR}/run-tests)

.include <bsd.port.mk>
