PORTNAME=	sessioninfo
DISTVERSION=	1.2.3
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
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

MAKE_ENV+=	LC_ALL="C.UTF-8"

.include <bsd.port.mk>
