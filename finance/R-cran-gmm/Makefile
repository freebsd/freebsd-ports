PORTNAME=	gmm
DISTVERSION=	1.8
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Generalized Method of Moments and Generalized Empirical Likelihood
WWW=		https://cran.r-project.org/web/packages/gmm/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-sandwich>0:math/R-cran-sandwich
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
