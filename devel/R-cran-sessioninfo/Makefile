PORTNAME=	sessioninfo
DISTVERSION=	1.2.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	R Session Information
WWW=		https://cran.r-project.org/package=sessioninfo

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-cli>=3.1.0:devel/R-cran-cli
TEST_DEPENDS=	R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-gh>0:www/R-cran-gh \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.2.0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
