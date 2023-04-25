PORTNAME=	progressr
PORTVERSION=	0.13.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Inclusive, Unifying API for Progress Updates
WWW=		https://cran.r-project.org/web/packages/progressr/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
