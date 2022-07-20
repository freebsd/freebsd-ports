PORTNAME=	rngtools
PORTVERSION=	1.5.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Utility functions for working with Random Number Generators

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
