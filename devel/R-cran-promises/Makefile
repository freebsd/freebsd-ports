PORTNAME=	promises
PORTVERSION=	1.5.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Abstractions for Promise-Based Asynchronous Programming
WWW=		https://cran.r-project.org/web/packages/promises/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-fastmap>=1.1.0:databases/R-cran-fastmap \
		R-cran-later>0:devel/R-cran-later \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-magrittr>=1.5:devel/R-cran-magrittr \
		R-cran-otel>=0.2.0:devel/R-cran-otel \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rlang>0:devel/R-cran-rlang

USES=		cran:auto-plist

.include <bsd.port.mk>
