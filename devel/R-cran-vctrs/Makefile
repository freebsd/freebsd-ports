# $FreeBSD$

PORTNAME=	vctrs
PORTVERSION=	0.1.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Vector Helpers

LICENSE=	GPLv3

USES=		cran:auto-plist,compiles

CRAN_DEPENDS=	R-cran-backports>0:math/R-cran-backports \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-zeallot>0:devel/R-cran-zeallot
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

.include <bsd.port.mk>
