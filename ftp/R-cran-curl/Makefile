PORTNAME=	curl
DISTVERSION=	6.0.1
CATEGORIES=	ftp
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Modern and Flexible Web Client for R
WWW=		https://cran.r-project.org/web/packages/curl/

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/curl/curl.h:ftp/curl
LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	R-cran-httpuv>=1.4.4:www/R-cran-httpuv \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-later>0:devel/R-cran-later \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-testthat>=1.0.0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

TESTING_UNSAFE=	yes

pre-test:
# R-cran-webutils package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("webutils", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
