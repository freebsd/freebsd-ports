PORTNAME=	curl
DISTVERSION=	7.0.0
CATEGORIES=	ftp
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Modern and Flexible Web Client for R
WWW=		https://cran.r-project.org/package=curl

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/curl/curl.h:ftp/curl
LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	R-cran-httpuv>=1.4.4:www/R-cran-httpuv \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-later>0:devel/R-cran-later \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-testthat>=1.0.0:devel/R-cran-testthat \
		R-cran-webutils>0:www/R-cran-webutils

USES=		cran:auto-plist,compiles

do-test:
	@${FIND} ${WRKSRC} \( -name '*.o' -o -name '*.so' \) -delete
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${LOCALBASE}/bin/R CMD check --no-manual ${PORTNAME}

.include <bsd.port.mk>
