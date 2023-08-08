PORTNAME=	hms
PORTVERSION=	1.1.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Pretty Time of Day
WWW=		https://cran.r-project.org/web/packages/hms/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-rlang>=1.0.2:devel/R-cran-rlang \
		R-cran-vctrs>=0.3.8:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
