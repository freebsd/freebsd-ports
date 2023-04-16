PORTNAME=	vctrs
PORTVERSION=	0.6.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Vector Helpers
WWW=		https://cran.r-project.org/web/packages/vctrs/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>=3.4.0:devel/R-cran-cli \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-rlang>=1.0.6:devel/R-cran-rlang \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
