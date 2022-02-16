# Created by: Pedro Giffuni

PORTNAME=	crayon
DISTVERSION=	1.5.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Colored Terminal Output

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
