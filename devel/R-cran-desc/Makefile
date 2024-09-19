PORTNAME=	desc
DISTVERSION=	1.4.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Manipulate DESCRIPTION Files
WWW=		https://github.com/r-lib/desc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rprojroot>0:devel/R-cran-rprojroot
TEST_DEPENDS=	R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-gh>0:www/R-cran-gh \
		R-cran-spelling>0:textproc/R-cran-spelling \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-whoami>0:devel/R-cran-whoami \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
