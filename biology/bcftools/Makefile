# Created by: Reed A. Cartwright <cartwright@asu.edu>

PORTNAME=	bcftools
PORTVERSION=	1.14
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools for manipulating next-generation sequencing data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhts.so:biology/htslib
TEST_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake localbase perl5 python:env shebangfix

USE_GITHUB=	yes
USE_PERL5=	test

GH_ACCOUNT=	samtools
GNU_CONFIGURE=	yes
SHEBANG_FILES=	misc/* test/test.pl

OPTIONS_DEFINE=		GPL
GPL_DESC=		Enable modules that rely on GPL code
OPTIONS_DEFAULT=	GPL

GPL_LIB_DEPENDS=	libgsl.so:math/gsl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPL}
MAKE_ENV+=	USE_GPL=1
LICENSE+=	GPLv3
LICENSE_COMB=	multi
.endif

TEST_TARGET=	test

pre-configure:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' \
		${WRKSRC}/configure.ac

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/color-chrs.pl \
		${STAGEDIR}${PREFIX}/bin/color-chrs
	${MV} ${STAGEDIR}${PREFIX}/bin/guess-ploidy.py\
	       ${STAGEDIR}${PREFIX}/bin/guess-ploidy
	${MV} /${STAGEDIR}${PREFIX}/bin/plot-roh.py \
		${STAGEDIR}${PREFIX}/bin/plot-roh
	${MV} ${STAGEDIR}${PREFIX}/bin/run-roh.pl \
		${STAGEDIR}${PREFIX}/bin/run-roh
	${MV} ${STAGEDIR}${PREFIX}/bin/vcfutils.pl \
		${STAGEDIR}${PREFIX}/bin/vcfutils
	${MV} ${STAGEDIR}${PREFIX}/bin/plot-vcfstats \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
