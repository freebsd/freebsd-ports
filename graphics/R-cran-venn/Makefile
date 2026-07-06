PORTNAME=	venn
DISTVERSION=	1.13
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Draw and display Venn diagrams up to 7 sets
WWW=		https://cran.r-project.org/package=venn

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-admisc>=0.33:math/R-cran-admisc
TEST_DEPENDS=	R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-ggpolypath>0:graphics/R-cran-ggpolypath

USES=		cran:auto-plist

.include <bsd.port.mk>
