PORTNAME=	pak
DISTVERSION=	0.3.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Another Approach to Package Installation

LICENSE=	GPLv3

TEST_DEPENDS=	R-cran-jsonlite>=1.8.0:converters/R-cran-jsonlite \
		R-cran-callr>=3.7.0:devel/R-cran-callr \
		R-cran-cli>=3.2.0:devel/R-cran-cli \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-desc>=1.4.1:devel/R-cran-desc \
		R-cran-filelock>=1.0.2:devel/R-cran-filelock \
		R-cran-glue>=1.6.2:devel/R-cran-glue \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-pkgcache>=2.0.1:devel/R-cran-pkgcache \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-rprojroot>=2.0.2:devel/R-cran-rprojroot \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-curl>=4.3.2:ftp/R-cran-curl \
		R-cran-pingr>0:net/R-cran-pingr \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-gitcreds>0:security/R-cran-gitcreds \
		R-cran-processx>=3.5.2:sysutils/R-cran-processx \
		R-cran-ps>=1.6.0:sysutils/R-cran-ps

USES=		cran:auto-plist

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/library" >> ${TMPPLIST}

.include <bsd.port.mk>
