PORTNAME=	magick
DISTVERSION=	2.7.4
PORTREVISION=	2
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Advanced Graphics and Image-Processing in R
WWW=		https://cran.r-project.org/web/packages/magick/index.html

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS+=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles magick:run

.include <bsd.port.mk>
