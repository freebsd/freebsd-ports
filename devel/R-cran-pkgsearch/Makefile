PORTNAME=	pkgsearch
DISTVERSION=	3.1.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Search and Query CRAN R Packages
WWW=		https://github.com/r-hub/pkgsearch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-parsedate>=1.3.0:devel/R-cran-parsedate \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-curl>0:ftp/R-cran-curl
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-memoise>0:devel/R-cran-memoise \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-pillar>0:devel/R-cran-pillar \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>=2.1.0:devel/R-cran-testthat \
		R-cran-whoami>0:devel/R-cran-whoami \
		R-cran-pingr>=2.0.0:net/R-cran-pingr \
		R-cran-shiny>0:www/R-cran-shiny \
		R-cran-shinyjs>0:www/R-cran-shinyjs

USES=		cran:auto-plist

.include <bsd.port.mk>
