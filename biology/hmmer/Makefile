# Created by: barnhart@genetics.wustl.edu
# $FreeBSD$

PORTNAME=	hmmer
PORTVERSION=	3.2.1
CATEGORIES=	biology
MASTER_SITES=	http://eddylab.org/software/hmmer/

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	Profile hidden Markov models for biological sequence analysis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386 ia64 powerpc powerpc64
ONLY_FOR_ARCHS_REASON=	requires SSE2 or AltiVec instructions

USES=		gmake perl5 shebangfix

GNU_CONFIGURE=	yes
MAKE_ARGS=	V=1

TEST_TARGET=	check
USE_PERL5=	test
SHEBANG_GLOB=	*.pl
SHEBANG_FILES=	easel/devkit/*

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

DOCFILES=	Userguide.pdf
EXAMPLES=	7LESS_DROME HBB_HUMAN MADE1.hmm MADE1.sto \
		Pkinase.hmm Pkinase.sto dna_target.fa fn3.hmm fn3.sto \
		globins4.hmm globins4.sto globins45.fa

TEST_VARS=	use_perl5=build

post-build-TEST-on:	do-test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/tutorial/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
