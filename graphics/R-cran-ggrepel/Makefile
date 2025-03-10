PORTNAME=	ggrepel
DISTVERSION=	0.9.6
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Help to avoid overlapping text labels of ggplot2
WWW=		https://cran.r-project.org/web/packages/ggrepel/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-ggplot2>2.2.0:graphics/R-cran-ggplot2 \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-rlang>=0.3.0:devel/R-cran-rlang \
		R-cran-scales>=0.5.0:graphics/R-cran-scales \
		R-cran-withr>=2.5.0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
