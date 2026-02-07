PORTNAME=	pkgmaker
PORTVERSION=	0.32.10
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Package development utilities
WWW=		https://cran.r-project.org/web/packages/pkgmaker/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-assertthat>0:math/R-cran-assertthat \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-registry>0:devel/R-cran-registry \
		R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-xtable>0:textproc/R-cran-xtable
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
