PORTNAME=	msm
PORTVERSION=	1.8.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Multi-State Markov and Hidden Markov Models in Continuous Time
WWW=		https://cran.r-project.org/package=msm

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-expm>0:math/R-cran-expm	\
		R-cran-tibble>0:devel/R-cran-tibble	\
		R-cran-mvtnorm>0:math/R-cran-mvtnorm	\
		R-cran-generics>0:devel/R-cran-generics
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:compiles

.include <bsd.port.mk>
