# Created by: Reed A. Cartwright <cartwright@asu.edu>
# $FreeBSD$

PORTNAME=	bcftools
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	cartwright@asu.edu
COMMENT=	Tools for manipulating next-generation sequencing data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	htslib>=1.6:biology/htslib
LIB_DEPENDS=	libhts.so:biology/htslib
TEST_DEPENDS=	bash:shells/bash

CONFLICTS_BUILD=openssl

USES=		autoreconf gmake localbase \
		perl5 python:env shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	samtools

USE_LDCONFIG=	${PREFIX}/libexec/${PORTNAME}
USE_PERL5=	test
GNU_CONFIGURE=	yes
SHEBANG_FILES=	misc/* test/test.pl

OPTIONS_DEFINE=	GPL
GPL_DESC=	Enable modules that rely on GPL code
OPTIONS_DEFAULT=	GPL

GPL_LIB_DEPENDS=	libgsl.so:math/gsl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPL}
MAKE_ENV+=	USE_GPL=1
LICENSE+=	GPLv3
LICENSE_COMB=	multi
.endif

TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' ${WRKSRC}/configure.ac

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/samtools_misc/color-chrs.pl \
		${STAGEDIR}${PREFIX}/bin/color-chrs
	${MV} ${STAGEDIR}${PREFIX}/bin/samtools_misc/guess-ploidy.py\
	       ${STAGEDIR}${PREFIX}/bin/guess-ploidy
	${MV} /${STAGEDIR}${PREFIX}/bin/samtools_misc/plot-roh.py \
		${STAGEDIR}${PREFIX}/bin/plot-roh
	${MV} ${STAGEDIR}${PREFIX}/bin/samtools_misc/run-roh.pl \
		${STAGEDIR}${PREFIX}/bin/run-roh
	${MV} ${STAGEDIR}${PREFIX}/bin/samtools_misc/vcfutils.pl \
		${STAGEDIR}${PREFIX}/bin/vcfutils
	${MV} ${STAGEDIR}${PREFIX}/bin/samtools_misc/plot-vcfstats \
		${STAGEDIR}${PREFIX}/bin/
	${RMDIR} ${STAGEDIR}${PREFIX}/bin/samtools_misc/

.include <bsd.port.mk>
