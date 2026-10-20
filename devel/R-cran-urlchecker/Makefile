PORTNAME=	urlchecker
DISTVERSION=	2.0.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	URL checking tools

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-cli>=2.4.0:devel/R-cran-cli \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-gitcreds>0:security/R-cran-gitcreds \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-xml2>0:textproc/R-cran-xml2
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-webfakes>0:devel/R-cran-webfakes \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
