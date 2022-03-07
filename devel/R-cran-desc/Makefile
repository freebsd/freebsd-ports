PORTNAME=	desc
DISTVERSION=	1.4.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Manipulate DESCRIPTION Files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-cli>0:devel/R-cran-cli \
		R-cran-rprojroot>0:devel/R-cran-rprojroot
TEST_DEPENDS=	R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-gh>0:www/R-cran-gh

USES=		cran:auto-plist

.include <bsd.port.mk>
