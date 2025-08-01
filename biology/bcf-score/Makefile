PORTNAME=	bcf-score
DISTVERSION=	1.20
PORTREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	https://software.broadinstitute.org/software/score/
# Get this right, or ports will download bcftools in it's place via tuple
DISTFILES+=	score_${DISTVERSION}-20240505.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bcftools plugins for GWAS-VCF summary statistics files
WWW=		https://software.broadinstitute.org/software/score/

LICENSE=	MIT

BUILD_DEPENDS=	htslib>=1.22:biology/htslib
LIB_DEPENDS=	libhts.so:biology/htslib libcholmod.so:math/suitesparse-cholmod
TEST_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash bcftools>=${PORTVERSION}:biology/bcftools

USES=		autoreconf gmake localbase perl5 python:env shebangfix
USE_GITHUB=	yes
USE_PERL5=	test

GH_ACCOUNT=	samtools
GH_PROJECT=	bcftools
GH_TAGNAME=	1.22
GNU_CONFIGURE=	yes
SHEBANG_FILES=	misc/* test/test.pl

# From pgs.mk
CFLAGS+=	-isystem ${LOCALBASE}/include/suitesparse
LDFLAGS+=	-lcholmod

pre-configure:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' \
		${WRKSRC}/configure.ac

post-extract:
	@${CP} ${WRKDIR}/*.c ${WRKDIR}/*.h ${WRKSRC}/plugins
	@${MKDIR} ${WRKSRC}/bcf-score
	@${CP} ${WRKDIR}/*.R ${WRKSRC}/bcf-score

# One .so for each .c in the score distfile
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/blup.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/liftover.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/metal.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/munge.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/pgs.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/score.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	(cd ${WRKSRC}/bcf-score && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
