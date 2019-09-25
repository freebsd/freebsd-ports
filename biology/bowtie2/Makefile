# $FreeBSD$

PORTNAME=		bowtie2
DISTVERSIONPREFIX=	v
DISTVERSION=		2.3.5.1
PORTREVISION=		1
CATEGORIES=		biology perl5 python

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultrafast, memory-efficient short read aligner

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

# Requires a 64-bit processor and depends on hard-coded SSE instructions
# Experimental support for AARCH64 as of 2.3.5
ONLY_FOR_ARCHS=	amd64
LIB_DEPENDS=	libtbb.so:devel/tbb
RUN_DEPENDS=	bash:shells/bash

USES=		gmake localbase:ldflags perl5 python shebangfix
USE_PERL5=	run
USE_GITHUB=	yes

SHEBANG_FILES=	bowtie2 bowtie2-build bowtie2-inspect \
		scripts/bowtie2-hbb.sh scripts/*.pl
GH_ACCOUNT=	BenLangmead

OPTIONS_DEFINE=	DOCS EXAMPLES

SUB_FILES=	bowtie2-test

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|^RELEASE_FLAGS|# RELEASE_FLAGS|' \
		-e 's|tbbmalloc_proxy|tbbmalloc|' \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/scripts
	${INSTALL_PROGRAM} \
		${WRKSRC}/bowtie2*-s \
		${WRKSRC}/bowtie2*-l \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${STAGEDIR}${DATADIR}/scripts
	${INSTALL_SCRIPT} ${WRKDIR}/bowtie2-test ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
