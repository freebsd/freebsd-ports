PORTNAME=	cachem
PORTVERSION=	1.0.5
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Cache R Objects with Automatic Pruning

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-fastmap>0:databases/R-cran-fastmap
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
