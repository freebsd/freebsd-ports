# $FreeBSD$

PORTNAME=	ggplot2
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Implementation of the Grammar of Graphics

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-gtable>=0.1.1:math/R-cran-gtable \
		R-cran-plyr>=1.7.1:devel/R-cran-plyr \
		R-cran-reshape2>0:devel/R-cran-reshape2 \
		R-cran-scales>=0.4.1:graphics/R-cran-scales \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-lazyeval>0:math/R-cran-lazyeval
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
