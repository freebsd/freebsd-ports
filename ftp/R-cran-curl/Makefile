PORTNAME=	curl
DISTVERSION=	5.2.0
CATEGORIES=	ftp
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Modern and Flexible Web Client for R
WWW=		https://cran.r-project.org/web/packages/curl/

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/curl/curl.h:ftp/curl
LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-httpuv>0:www/R-cran-httpuv \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist,compiles

pre-test:
	# R-cran-webutils package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("webutils", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
