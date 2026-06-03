PORTNAME=	fBasics
DISTVERSION=	4052.98
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Rmetrics - Markets and Basic Statistics
WWW=		https://r-forge.r-project.org/scm/viewvc.php/pkg/fBasics/?root=rmetrics

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-timeDate>0:finance/R-cran-timeDate \
		R-cran-timeSeries>=4021.105:finance/R-cran-timeSeries \
		R-cran-gss>0:math/R-cran-gss \
		R-cran-stabledist>0:math/R-cran-stabledist
TEST_DEPENDS=	R-cran-RUnit>0:devel/R-cran-RUnit

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
