PORTNAME=	vctrs
PORTVERSION=	0.4.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Vector Helpers

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>=3.2.0:devel/R-cran-cli \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-rlang>=1.0.2:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
