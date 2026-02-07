PORTNAME=	webfakes
DISTVERSION=	1.4.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Fake Web Apps for HTTP Testing
WWW=		https://cran.r-project.org/package=webfakes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-brotli>0:archivers/R-cran-brotli \
		R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-httpuv>0:www/R-cran-httpuv \
		R-cran-httr>0:www/R-cran-httr \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-processx>0:sysutils/R-cran-processx \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-xml2>0:textproc/R-cran-xml2 \
		R-cran-zip>=2.3.0:archivers/R-cran-zip

USES=		cran:auto-plist,compiles shebangfix

SHEBANG_FILES=	inst/cert/localhost/generate.sh

.include <bsd.port.mk>
