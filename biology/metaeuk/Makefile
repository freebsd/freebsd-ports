PORTNAME=	metaeuk
DISTVERSION=	6
PORTREVISION=	1
DISTVERSIONSUFFIX=	-a5d39d9
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gene discovery and annotation for large-scale eukaryotic metagenomics
WWW=		https://github.com/soedinglab/metaeuk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE.md

.if !exists(/usr/include/omp.h)
CMAKE_ARGS+=	-DREQUIRE_OPENMP=0
.endif

BUILD_DEPENDS=	xxd:editors/vim
TEST_DEPENDS=	bash:shells/bash

USES=		cmake perl5 shebangfix
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	soedinglab
GH_TUPLE=	soedinglab:metaeuk-regression:6404519:metaeuk_regression/tests \
		soedinglab:MMseqs2-Regression:f69b185:MMseqs2_Regression/lib/mmseqs/util/regression

SHEBANG_GLOB=	*.sh

PLIST_FILES=	bin/metaeuk

CMAKE_OFF=	NATIVE_ARCH

.if !exists(/usr/include/omp.h)
CMAKE_ARGS+=	-DREQUIRE_OPENMP:BOOL=OFF
.endif

do-test:
	@cd ${WRKSRC}/tests && ./run.sh ${STAGEDIR}${PREFIX}/bin/metaeuk

.include <bsd.port.mk>
