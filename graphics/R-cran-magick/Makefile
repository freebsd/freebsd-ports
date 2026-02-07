PORTNAME=	magick
DISTVERSION=	2.9.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Advanced Graphics and Image-Processing in R
WWW=		https://cran.r-project.org/package=magick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS+=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-gapminder>0:misc/R-cran-gapminder \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-pdftools>0:graphics/R-cran-pdftools \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-webp>0:graphics/R-cran-webp

USES=		compiler:c++17-lang cran:auto-plist,compiles magick:run

.include <bsd.port.mk>
