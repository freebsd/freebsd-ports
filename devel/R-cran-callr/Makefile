PORTNAME=	callr
DISTVERSION=	3.7.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Call R from R

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-processx>=3.6.1:sysutils/R-cran-processx
TEST_DEPENDS=	R-cran-cli>=1.1.0:devel/R-cran-cli \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-withr>=2.3.0:devel/R-cran-withr \
		R-cran-ps>0:sysutils/R-cran-ps \
		R-cran-spelling>0:textproc/R-cran-spelling

USES=		cran:auto-plist

.include <bsd.port.mk>
