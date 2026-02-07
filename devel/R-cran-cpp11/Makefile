PORTNAME=	cpp11
DISTVERSION=	0.5.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C++11 Interface for R's C Interface
WWW=		https://cran.r-project.org/package=cpp11

LICENSE=	MIT

TEST_DEPENDS=	R-cran-decor>0:devel/R-cran-decor \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-progress>0:devel/R-cran-progress \
		R-cran-testthat>0:devel/R-cran-testthat

TESTING_UNSAFE=	https://github.com/r-lib/cpp11/issues/419

USES=		cran:auto-plist

pre-test:
# R-cran-bench package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("bench", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
