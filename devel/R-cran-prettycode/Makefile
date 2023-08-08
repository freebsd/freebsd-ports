PORTNAME=	prettycode
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Pretty Print R Code in the Terminal
WWW=		https://github.com/r-lib/prettycode #readme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-crayon>0:devel/R-cran-crayon
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
