PORTNAME=	tibble
PORTVERSION=	3.1.8
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple Data Frames

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-fansi>=0.4.0:devel/R-cran-fansi \
		R-cran-lifecycle>=1.0.0:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-pillar>=1.7.0:devel/R-cran-pillar \
		R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-rlang>=1.0.2:devel/R-cran-rlang \
		R-cran-vctrs>=0.3.8:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
