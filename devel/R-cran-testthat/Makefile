PORTNAME=	testthat
DISTVERSION=	3.2.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Unit Testing for R
WWW=		https://testthat.r-lib.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-brio>=1.1.3:devel/R-cran-brio \
		R-cran-callr>=3.7.3:devel/R-cran-callr \
		R-cran-cli>=3.6.1:devel/R-cran-cli \
		R-cran-desc>=1.4.2:devel/R-cran-desc \
		R-cran-digest>=0.6.33:security/R-cran-digest \
		R-cran-ellipsis>=0.2.0:devel/R-cran-ellipsis \
		R-cran-evaluate>=0.21:devel/R-cran-evaluate \
		R-cran-jsonlite>=1.8.7:converters/R-cran-jsonlite \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>=2.0.3:devel/R-cran-magrittr \
		R-cran-pkgload>=1.3.2.1:devel/R-cran-pkgload \
		R-cran-praise>=1.0.0:devel/R-cran-praise \
		R-cran-processx>=3.8.2:sysutils/R-cran-processx \
		R-cran-ps>=1.3.4:sysutils/R-cran-ps \
		R-cran-R6>=2.2.0:devel/R-cran-R6 \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-waldo>=0.5.0:devel/R-cran-waldo \
		R-cran-withr>=2.4.3:devel/R-cran-withr
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-curl>=0.9.5:ftp/R-cran-curl \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-shiny>0:www/R-cran-shiny \
		R-cran-usethis>0:devel/R-cran-usethis \
		R-cran-xml2>0:textproc/R-cran-xml2
# testunit fails: https://github.com/r-lib/testthat/issues/1924

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
