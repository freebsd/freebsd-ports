# Created by: Guangyuan Yang <ygy@FreeBSD.org>

PORTNAME=	mockery
DISTVERSION=	0.4.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Mocking Library for R

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat
TEST_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>=1.0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist

.include <bsd.port.mk>
