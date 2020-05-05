# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tibble
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple Data Frames

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-crayon>=1.3.4:devel/R-cran-crayon \
		R-cran-ellipsis>=0.2.0:devel/R-cran-ellipsis \
		R-cran-fansi>=0.4.0:devel/R-cran-fansi \
		R-cran-lifecycle>=0.2.0:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-pillar>=1.4.3:devel/R-cran-pillar \
		R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-rlang>=0.4.3:devel/R-cran-rlang \
		R-cran-vctrs>=0.2.4:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
