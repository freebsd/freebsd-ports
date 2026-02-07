PORTNAME=	rversions
DISTVERSION=	3.0.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Query 'R' Versions, Including 'r-release' and 'r-oldrel'
WWW=		https://github.com/r-hub/rversions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl
TEST_DEPENDS=	R-cran-pillar>0:devel/R-cran-pillar \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-webfakes>0:devel/R-cran-webfakes \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
