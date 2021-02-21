# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	broom
DISTVERSION=	0.7.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Convert Statistical Analysis Objects into Tidy Data Frames

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-backports>0:math/R-cran-backports \
		R-cran-dplyr>=1.0.0:math/R-cran-dplyr \
		R-cran-ellipsis>0:devel/R-cran-ellipsis \
		R-cran-generics>=0.0.2:devel/R-cran-generics \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-tibble>=3.0.0:devel/R-cran-tibble \
		R-cran-tidyr>=1.0.0:devel/R-cran-tidyr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
