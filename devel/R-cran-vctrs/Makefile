PORTNAME=	vctrs
PORTVERSION=	0.3.8
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Vector Helpers

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-ellipsis>=0.2.0:devel/R-cran-ellipsis \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
