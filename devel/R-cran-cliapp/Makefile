PORTNAME=	cliapp
DISTVERSION=	0.1.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Create Rich Command Line Applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-cli>0:devel/R-cran-cli \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-fansi>0:devel/R-cran-fansi \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-prettycode>0:devel/R-cran-prettycode \
		R-cran-progress>=1.2.0:devel/R-cran-progress \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-xml2>0:textproc/R-cran-xml2 \
		R-cran-selectr>0:www/R-cran-selectr
TEST_DEPENDS=	R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
