# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	hms
PORTVERSION=	1.1.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Pretty Time of Day

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-ellipsis>=0.3.2:devel/R-cran-ellipsis \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-vctrs>=0.3.8:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
