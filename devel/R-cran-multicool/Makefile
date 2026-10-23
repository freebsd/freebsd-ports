PORTNAME=	multicool
DISTVERSION=	1.0.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Permutations of Multisets in Cool-Lex Order
WWW=		https://cran.r-project.org/package=multicool

LICENSE=	GPLv2

BUILD_RUN_DEPENDS=	R-cran-gmp>0:math/R-cran-gmp
RUN_DEPENDS=		R-cran-Rcpp>0:devel/R-cran-Rcpp

USES=		compiler:c++11-lang cran:compiles

.include <bsd.port.mk>
