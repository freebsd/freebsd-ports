PORTNAME=	callr
DISTVERSION=	3.8.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Call R from R
WWW=		https://callr.r-lib.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-otel>=0.2.0:devel/R-cran-otel \
		R-cran-processx>=3.6.1:sysutils/R-cran-processx \
		R-cran-R6>0:devel/R-cran-R6
TEST_DEPENDS=	R-cran-cli>=1.1.0:devel/R-cran-cli \
		R-cran-ps>0:sysutils/R-cran-ps \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-testthat>=3.2.0:devel/R-cran-testthat \
		R-cran-withr>=2.3.0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
