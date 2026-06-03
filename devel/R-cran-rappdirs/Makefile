PORTNAME=	rappdirs
DISTVERSION=	0.3.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Application Directories: Determine Where to Save Data, Caches, and Logs
WWW=		https://rappdirs.r-lib.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-roxygen2>0:devel/R-cran-roxygen2 \
		R-cran-testthat>=3.2.0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
