# $FreeBSD$

PORTNAME=	infernal
PORTVERSION=	1.1.3
CATEGORIES=	biology
MASTER_SITES=	http://eddylab.org/infernal/

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	Search sequence databases for structural RNA homologs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le powerpcspe
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
EXAMPLES=	5S_rRNA.c.cm 5S_rRNA.sto \
		Cobalamin.c.cm Cobalamin.fa Cobalamin.sto \
		metag-example.fa minifam-metag.out minifam.cm \
		minifam.cm.i1f minifam.cm.i1i minifam.cm.i1m minifam.cm.i1p \
		mrum-genome.fa mrum-tRNAs10.fa mrum-tRNAs10.out \
		tRNA5-hand.c.cm tRNA5-hand.sto tRNA5-mrum.out \
		tRNA5-noss.sto tRNA5.c.cm tRNA5.sto

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
