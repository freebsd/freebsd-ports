# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tibble
PORTVERSION=	2.1.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple Data Frames

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-crayon>=1.3.4:devel/R-cran-crayon \
		R-cran-fansi>=0.4.0:devel/R-cran-fansi \
		R-cran-pillar>=1.3.1:devel/R-cran-pillar \
		R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-rlang>=0.3.0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
