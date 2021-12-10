# Created by: Guangyuan Yang <ygy@FreeBSD.org>

PORTNAME=	lintr
DISTVERSION=	2.0.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	A 'Linter' for R Code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-cyclocomp>0:devel/R-cran-cyclocomp \
		R-cran-rstudioapi>=0.2:devel/R-cran-rstudioapi \
		R-cran-testthat>=2.2.1:devel/R-cran-testthat \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-rex>0:textproc/R-cran-rex \
		R-cran-xml2>=1.0.0:textproc/R-cran-xml2 \
		R-cran-xmlparsedata>=1.0.3:textproc/R-cran-xmlparsedata \
		R-cran-httr>=1.2.1:www/R-cran-httr
TEST_DEPENDS=	R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist

.include <bsd.port.mk>
