PORTNAME=	plm
DISTVERSION=	2.6-7
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Linear Models for Panel Data
WWW=		https://cran.r-project.org/web/packages/plm/

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-bdsmatrix>0:math/R-cran-bdsmatrix \
		R-cran-collapse>=1.8.9:devel/R-cran-collapse \
		R-cran-Formula>0:math/R-cran-Formula \
		R-cran-lmtest>0:finance/R-cran-lmtest \
		R-cran-maxLik>0:math/R-cran-maxLik \
		R-cran-Rdpack>0:devel/R-cran-Rdpack \
		R-cran-sandwich>0:math/R-cran-sandwich \
		R-cran-zoo>0:math/R-cran-zoo

USES=		cran:auto-plist

.include <bsd.port.mk>
