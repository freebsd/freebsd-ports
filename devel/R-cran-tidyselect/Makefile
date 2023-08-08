PORTNAME=	tidyselect
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Select from a Set of Strings
WWW=		https://cran.r-project.org/web/packages/tidyselect/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-ellipsis>0:devel/R-cran-ellipsis \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-purrr>=0.3.2:devel/R-cran-purrr \
		R-cran-rlang>=1.0.1:devel/R-cran-rlang \
		R-cran-vctrs>=0.3.0:devel/R-cran-vctrs \
		R-cran-withr>=0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
