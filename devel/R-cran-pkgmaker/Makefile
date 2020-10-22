# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkgmaker
PORTVERSION=	0.32.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Package development utilities

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-registry>0:devel/R-cran-registry \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-xtable>0:textproc/R-cran-xtable \
		R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-assertthat>0:math/R-cran-assertthat
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
