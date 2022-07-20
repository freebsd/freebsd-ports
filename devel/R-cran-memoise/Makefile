PORTNAME=	memoise
PORTVERSION=	2.0.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Memoise functions for R

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-cachem>0:databases/R-cran-cachem
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
