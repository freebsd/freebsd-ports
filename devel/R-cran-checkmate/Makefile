PORTNAME=	checkmate
DISTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Fast and versatile argument checks
WWW=		https://cran.r-project.org/web/packages/checkmate/

LICENSE=	BSD3CLAUSE

CRAN_DEPENDS=	R-cran-backports>0:math/R-cran-backports
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
