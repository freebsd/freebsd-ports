# Created by: barnhart@genetics.wustl.edu
# $FreeBSD$

PORTNAME=	hmmer
PORTVERSION=	3.1b2
CATEGORIES=	biology
MASTER_SITES=	http://eddylab.org/software/hmmer3/${PORTVERSION}/

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	Profile hidden Markov models for biological sequence analysis

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_ARGS=	V=1

OPTIONS_DEFINE=	DOCS EXAMPLES TEST
TEST_TEST_TARGET=	check
TEST_USES=	shebangfix perl5
TEST_VARS=	shebang_glob=*.pl shebang_files=easel/devkit/* use_perl5=build

DOCFILES=	COPYRIGHT Userguide.pdf
EXAMPLES=	7LESS_DROME HBB_HUMAN MADE1.hmm MADE1.out MADE1.sto \
		Pkinase.hmm Pkinase.sto dna_target.fa fn3.hmm fn3.out fn3.sto \
		globins4.hmm globins4.out globins4.sto globins45.fa \
		minifam minifam.h3f minifam.h3i minifam.h3m minifam.h3p

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
