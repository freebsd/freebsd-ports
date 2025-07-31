PORTNAME=	future
DISTVERSION=	1.67.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Unified Parallel and Distributed Processing in R for Everyone
WWW=		https://cran.r-project.org/package=future

LICENSE=	LGPL21+

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-globals>=0.18.0:devel/R-cran-globals \
		R-cran-listenv>=0.8.0:devel/R-cran-listenv \
		R-cran-parallelly>=1.44.0:devel/R-cran-parallelly
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-R.rsp>0:textproc/R-cran-R.rsp

USES=		cran:auto-plist

.include <bsd.port.mk>
