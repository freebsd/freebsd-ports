PORTNAME=	lifecycle
PORTVERSION=	1.0.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Manage the Life Cycle of your Package Functions
WWW=		https://cran.r-project.org/web/packages/lifecycle/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-glue>0:devel/R-cran-glue \
		R-cran-rlang>=1.0.5:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
