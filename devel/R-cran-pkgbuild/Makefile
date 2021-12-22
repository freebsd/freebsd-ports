# Created by: Guangyuan Yang <ygy@FreeBSD.org>

PORTNAME=	pkgbuild
DISTVERSION=	1.3.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Find Tools Needed to Build R Packages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-callr>=3.2.0:devel/R-cran-callr \
		R-cran-cli>0:devel/R-cran-cli \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-withr>=2.3.0:devel/R-cran-withr
TEST_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp

USES=		cran:auto-plist

.include <bsd.port.mk>
