# $FreeBSD$

PORTNAME=	infernal
PORTVERSION=	1.1.2
CATEGORIES=	biology
MASTER_SITES=	http://eddylab.org/infernal/

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	Search sequence databases for structural RNA homologs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc64
ONLY_FOR_ARCHS_REASON=	requires SSE2 or AltiVec instructions

USES=		gmake
GNU_CONFIGURE=	yes
MAKE_ARGS=	V=1

DOCFILES=	Userguide.pdf
EXAMPLES=	5S_rRNA.c.cm 5S_rRNA.sto \
		Cobalamin.c.cm Cobalamin.fa Cobalamin.sto \
		metag-example.fa minifam-metag.out minifam.cm \
		minifam.cm.i1f minifam.cm.i1i minifam.cm.i1m minifam.cm.i1p \
		mrum-genome.fa mrum-tRNAs10.fa mrum-tRNAs10.out \
		tRNA5-hand.c.cm tRNA5-hand.sto tRNA5-mrum.out \
		tRNA5-noss.sto tRNA5.c.cm tRNA5.sto

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

TEST_TEST_TARGET=	check
TEST_USES=	shebangfix perl5
TEST_VARS=	shebang_glob=*.pl shebang_files=easel/devkit/* use_perl5=build

post-build-TEST-on:	do-test

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/tutorial/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
