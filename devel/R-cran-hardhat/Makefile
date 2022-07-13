PORTNAME=	hardhat
PORTVERSION=	1.2.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Construct Modeling Packages

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-glue>=1.6.2:devel/R-cran-glue \
		R-cran-rlang>=1.0.3:devel/R-cran-rlang \
		R-cran-tibble>=3.1.7:devel/R-cran-tibble \
		R-cran-vctrs>=0.4.1:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
