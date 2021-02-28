# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pillar
PORTVERSION=	1.5.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Coloured Formatting for Columns

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-crayon>=1.3.4:devel/R-cran-crayon \
		R-cran-ellipsis>0:devel/R-cran-ellipsis \
		R-cran-fansi>0:devel/R-cran-fansi \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-rlang>=0.3.0:devel/R-cran-rlang \
		R-cran-utf8>=1.1.0:textproc/R-cran-utf8 \
		R-cran-vctrs>0.2.0:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
