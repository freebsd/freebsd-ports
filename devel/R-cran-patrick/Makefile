PORTNAME=	patrick
DISTVERSION=	0.3.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Extension of the 'testthat' package
WWW=		https://cran.r-project.org/package=patrick

LICENSE=	APACHE20

RUN_DEPENDS=	R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-testthat>=3.2.0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble

USES=		cran:auto-plist

.include <bsd.port.mk>
