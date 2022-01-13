PORTNAME=	bio-mocha
DISTVERSION=	1.14
CATEGORIES=	biology
MASTER_SITES=	https://software.broadinstitute.org/software/mocha/
DISTFILES+=	${PORTNAME}_${DISTVERSION}-20220112.tar.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bcftools plugin for mosaic chromosomal alteration analysis

LICENSE=	MIT

LIB_DEPENDS=	libhts.so:biology/htslib
BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bcftools>=${PORTVERSION}:biology/bcftools

USES=		autoreconf gmake localbase perl5 python:env shebangfix
USE_GITHUB=	yes
USE_PERL5=	test

GH_ACCOUNT=	samtools
GH_PROJECT=	bcftools
GH_TAGNAME=	1.14
GNU_CONFIGURE=	yes
SHEBANG_FILES=	misc/* test/test.pl

post-extract:
	@${MV} ${WRKDIR}/*.c ${WRKDIR}/*.h ${WRKSRC}/plugins
	@${MKDIR} ${WRKSRC}/MoCha
	@${MV} ${WRKDIR}/*.R ${WRKSRC}/MoCha

pre-configure:
	@${REINPLACE_CMD} -e 's|@PORTVERSION@|${PORTVERSION}|g' \
		${WRKSRC}/configure.ac

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/extendFMT.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mocha.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/mochatools.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/score.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/trio-phase.so \
		${STAGEDIR}${PREFIX}/libexec/bcftools
	(cd ${WRKSRC}/MoCha && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
