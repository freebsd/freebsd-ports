PORTNAME=	cachem
PORTVERSION=	1.0.8
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Cache R Objects with Automatic Pruning
WWW=		https://cran.r-project.org/web/packages/cachem/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-fastmap>=1.1.1:databases/R-cran-fastmap \
		R-cran-rlang>0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
