# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	broom
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Convert Statistical Analysis Objects into Tidy Data Frames

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-backports>0:math/R-cran-backports \
		R-cran-plyr>0:devel/R-cran-plyr \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-tidyr>0:devel/R-cran-tidyr \
		R-cran-psych>0:math/R-cran-psych \
		R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-reshape2>0:devel/R-cran-reshape2
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
