PORTNAME=	future
PORTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Unified Parallel and Distributed Processing in R for Everyone
WWW=		https://cran.r-project.org/web/packages/future/

LICENSE=	LGPL21+

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-globals>=0.16.0:devel/R-cran-globals \
		R-cran-listenv>=0.8.0:devel/R-cran-listenv \
		R-cran-parallelly>=1.32.1:devel/R-cran-parallelly
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
