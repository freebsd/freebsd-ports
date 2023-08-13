PORTNAME=	progressr
DISTVERSION=	0.14.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Inclusive, Unifying API for Progress Updates
WWW=		https://cran.r-project.org/web/packages/progressr/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-future>0:devel/R-cran-future \
		R-cran-shiny>0:www/R-cran-shiny

USES=		cran:auto-plist

.include <bsd.port.mk>
