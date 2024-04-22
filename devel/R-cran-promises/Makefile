PORTNAME=	promises
PORTVERSION=	1.3.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Abstractions for Promise-Based Asynchronous Programming
WWW=		https://cran.r-project.org/web/packages/promises/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-fastmap>=1.1.0:databases/R-cran-fastmap \
		R-cran-later>0:devel/R-cran-later \
		R-cran-magrittr>=1.5:devel/R-cran-magrittr \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-rlang>0:devel/R-cran-rlang

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
