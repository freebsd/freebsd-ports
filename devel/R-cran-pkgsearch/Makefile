PORTNAME=	pkgsearch
DISTVERSION=	3.1.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Search and Query CRAN R Packages
WWW=		https://cran.r-project.org/package=pkgsearch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-jsonlite>0:converters/R-cran-jsonlite
TEST_DEPENDS=	R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
