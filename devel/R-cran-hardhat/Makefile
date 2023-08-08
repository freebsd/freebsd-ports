PORTNAME=	hardhat
PORTVERSION=	1.3.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Construct Modeling Packages
WWW=		https://cran.r-project.org/web/packages/hardhat/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>=3.6.0:devel/R-cran-cli \
		R-cran-glue>=1.6.2:devel/R-cran-glue \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-tibble>=3.2.1:devel/R-cran-tibble \
		R-cran-vctrs>=0.6.0:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
