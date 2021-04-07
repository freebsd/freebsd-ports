PORTNAME=	progress
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Terminal Progress Bars

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-hms>0:devel/R-cran-hms \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-crayon>0:devel/R-cran-crayon
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
