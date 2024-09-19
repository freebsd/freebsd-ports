PORTNAME=	crayon
DISTVERSION=	1.5.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Colored Terminal Output
WWW=		https://github.com/r-lib/crayon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
