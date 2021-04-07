PORTNAME=	lifecycle
PORTVERSION=	1.0.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Manage the Life Cycle of your Package Functions

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-glue>0:devel/R-cran-glue \
		R-cran-rlang>=0.4.0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
