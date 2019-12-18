# $FreeBSD$

PORTNAME=	vctrs
PORTVERSION=	0.2.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Vector Helpers

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-backports>0:math/R-cran-backports \
		R-cran-ellipsis>=0.2.0:devel/R-cran-ellipsis \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-rlang>=0.4.0:devel/R-cran-rlang \
		R-cran-zeallot>0:devel/R-cran-zeallot
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
