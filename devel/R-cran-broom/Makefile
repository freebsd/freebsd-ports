# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	broom
DISTVERSION=	0.5.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Convert Statistical Analysis Objects into Tidy Data Frames

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-backports>0:math/R-cran-backports \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-generics>=0.0.2:devel/R-cran-generics \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-reshape2>0:devel/R-cran-reshape2 \
		R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-tidyr>0:devel/R-cran-tidyr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
