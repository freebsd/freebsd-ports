PORTNAME=	pkgdepends
DISTVERSION=	0.5.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Package Dependency Resolution and Downloads
WWW=		https://github.com/r-lib/pkgdepends#readme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-zip>=2.3.0:archivers/R-cran-zip \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-callr>=3.3.1:devel/R-cran-callr \
		R-cran-cli>=3.6.0:devel/R-cran-cli \
		R-cran-desc>=1.2.0:devel/R-cran-desc \
		R-cran-filelock>=1.0.2:devel/R-cran-filelock \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-pkgbuild>=1.0.2:devel/R-cran-pkgbuild \
		R-cran-pkgcache>=2.1.0:devel/R-cran-pkgcache \
		R-cran-prettyunits>=1.1.1:devel/R-cran-prettyunits \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-withr>=2.1.1:devel/R-cran-withr \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-lpSolve>0:math/R-cran-lpSolve \
		R-cran-processx>=3.4.2:sysutils/R-cran-processx \
		R-cran-ps>0:sysutils/R-cran-ps
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-fansi>0:devel/R-cran-fansi \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-pak>0:devel/R-cran-pak \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-pingr>=2.0.0:net/R-cran-pingr \
		R-cran-fs>0:sysutils/R-cran-fs \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-htmlwidgets>0:www/R-cran-htmlwidgets

USES=		cran:auto-plist

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/help/figures" >> ${TMPPLIST}

.include <bsd.port.mk>
