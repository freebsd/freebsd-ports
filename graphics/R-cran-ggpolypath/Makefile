PORTNAME=	ggpolypath
DISTVERSION=	0.4.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Polygons with Holes for the Grammar of Graphics
WWW=		https://cran.r-project.org/package=ggpolypath

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-ggplot2>=2.1.0:graphics/R-cran-ggplot2
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cranr-markdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist

.include <bsd.port.mk>
