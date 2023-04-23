PORTNAME=	future.apply
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Apply Function to Elements in Parallel using Futures
WWW=		https://cran.r-project.org/web/packages/future.apply/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-future>=1.27.0:devel/R-cran-future \
		R-cran-globals>=0.16.1:devel/R-cran-globals
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
