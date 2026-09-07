PORTNAME=	languageserver
DISTVERSION=	0.3.18
CATEGORIES=	lang
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Language Server Protocol
WWW=		https://cran.r-project.org/package=languageserver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-callr>=3.0.0:devel/R-cran-callr \
		R-cran-collections>=0.3.0:math/R-cran-collections \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-fs>=1.3.1:filesystems/R-cran-fs \
		R-cran-jsonlite>=1.6:converters/R-cran-jsonlite \
		R-cran-lintr>=3.0.0:devel/R-cran-lintr \
		R-cran-R6>=2.4.1:devel/R-cran-R6 \
		R-cran-roxygen2>=7.0.0:devel/R-cran-roxygen2 \
		R-cran-stringi>=1.1.7:textproc/R-cran-stringi \
		R-cran-styler>=1.5.1:devel/R-cran-styler \
		R-cran-xml2>=1.2.2:textproc/R-cran-xml2 \
		R-cran-xmlparsedata>=1.0.3:textproc/R-cran-xmlparsedata
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>=3.4.0:devel/R-cran-covr \
		R-cran-magrittr>=1.5:devel/R-cran-magrittr \
		R-cran-mockery>=0.4.2:devel/R-cran-mockery \
		R-cran-processx>=3.4.1:sysutils/R-cran-processx \
		R-cran-purrr>=0.3.3:devel/R-cran-purrr \
		R-cran-rmarkdown>=2.0:textproc/R-cran-rmarkdown \
		R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-testthat>=2.1.0:devel/R-cran-testthat \
		R-cran-withr>=2.3.0:devel/R-cran-withr

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
