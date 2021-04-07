PORTNAME=	haplohseq
DISTVERSION=	0.1.2
PORTREVISION=	3
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify regions of allelic imbalance

LICENSE=	MIT

LIB_DEPENDS=	libboost_system.so:devel/boost-libs
RUN_DEPENDS=	R-cran-optparse>0:devel/R-cran-optparse

USES=		compiler:c++11-lang gmake localbase:ldflags python:3.6+
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

OPTIONS_DEFINE=	EXAMPLES

MAKEFILE=	makefile
LDFLAGS+=	-lpthread
MAKE_ENV=	STRIP=${STRIP}

SUB_FILES=	haplohseq-example

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
