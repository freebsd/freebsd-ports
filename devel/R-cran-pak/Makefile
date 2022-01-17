# Created by: Guangyuan Yang <ygy@FreeBSD.org>

PORTNAME=	pak
DISTVERSION=	0.2.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Another Approach to Package Installation

LICENSE=	GPLv3

TEST_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-callr>=3.5.0:devel/R-cran-callr \
		R-cran-cli>=3.0.0:devel/R-cran-cli \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-filelock>=1.0.2:devel/R-cran-filelock \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-pkgcache>=1.2.0:devel/R-cran-pkgcache \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-rprojroot>=1.3.2:devel/R-cran-rprojroot \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-pingr>0:net/R-cran-pingr \
		R-cran-processx>=3.5.1:sysutils/R-cran-processx \
		R-cran-ps>=1.6.0:sysutils/R-cran-ps

USES=		cran:auto-plist

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/library" >> ${TMPPLIST}

.include <bsd.port.mk>
