# $FreeBSD$

PORTNAME=	testthat
DISTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unit Testing for R

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-R6>=2.2.0:devel/R-cran-R6 \
		R-cran-cli>0:devel/R-cran-cli \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-praise>0:devel/R-cran-praise \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-withr>=2.0.0:devel/R-cran-withr \
		R-cran-digest>0:security/R-cran-digest
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-xml2>0:textproc/R-cran-xml2

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
