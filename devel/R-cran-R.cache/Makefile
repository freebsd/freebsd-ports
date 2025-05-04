PORTNAME=	R.cache
DISTVERSION=	0.17.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Caching (Memoization) of Objects and Results
WWW=		https://cran.r-project.org/package=R.cache

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-digest>=0.6.13:security/R-cran-digest \
		R-cran-R.methodsS3>=1.8.1:devel/R-cran-R.methodsS3 \
		R-cran-R.oo>=1.24.0:devel/R-cran-R.oo \
		R-cran-R.utils>=2.10.10:devel/R-cran-R.utils

USES=		cran:auto-plist

.include <bsd.port.mk>
