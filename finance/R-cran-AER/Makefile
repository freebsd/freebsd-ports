PORTNAME=	AER
DISTVERSION=	1.2-14
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Applied Econometrics with R
WWW=		https://cran.r-project.org/web/packages/AER/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-car>=2.0.19:math/R-cran-car \
		R-cran-lmtest>=0:finance/R-cran-lmtest \
		R-cran-Formula>=0.2.0:math/R-cran-Formula \
		R-cran-zoo>=0:math/R-cran-zoo

USES=	cran:auto-plist

.include <bsd.port.mk>
