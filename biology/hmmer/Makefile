# Created by: barnhart@genetics.wustl.edu
# $FreeBSD$

PORTNAME=	hmmer
PORTVERSION=	3.3
CATEGORIES=	biology
MASTER_SITES=	http://eddylab.org/software/hmmer/

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	Profile hidden Markov models for biological sequence analysis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64
ONLY_FOR_ARCHS_REASON=	requires SSE2 or AltiVec instructions

USES=		compiler:c11 gmake perl5 python:3.5+,test shebangfix

GNU_CONFIGURE=	yes
MAKE_ARGS=	V=1

TEST_TARGET=	check
USE_PERL5=	test
SHEBANG_GLOB=	*.pl *.py
SHEBANG_FILES=	easel/devkit/*

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

DOCFILES=	Userguide.pdf
EXAMPLES=	7LESS_DROME HBB_HUMAN MADE1.hmm MADE1.sto \
		Pkinase.hmm Pkinase.sto dna_target.fa fn3.hmm fn3.sto \
		globins4.hmm globins4.sto globins45.fa

TEST_VARS=	use_perl5=build
TEST_BUILD_DEPENDS=	${PYTHON_VERSION}:lang/python${PYTHON_SUFFIX}

post-build-TEST-on:	pre-test do-test

pre-test:
	${FIND} ${WRKSRC} -type f \( -name Makefile -or -name sqc \) -exec ${GREP} -q 'python3 ' {} \; -print | ${XARGS} ${SED} -i.bak 's/python3 /${PYTHON_VERSION} /'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/tutorial/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
