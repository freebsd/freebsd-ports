PORTNAME=	future.apply
DISTVERSION=	1.20.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Apply Function to Elements in Parallel using Futures
WWW=		https://cran.r-project.org/package=future.apply

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-future>=1.49.0:devel/R-cran-future \
		R-cran-globals>0:devel/R-cran-globals
TEST_DEPENDS=	R-cran-R.rsp>0:textproc/R-cran-R.rsp

USES=		cran:auto-plist

.include <bsd.port.mk>
