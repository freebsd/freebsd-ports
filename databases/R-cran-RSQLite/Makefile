PORTNAME=	RSQLite
PORTVERSION=	2.2.14
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Database Interface R driver for SQLite

LICENSE=	LGPL20

CRAN_DEPENDS=	R-cran-DBI>=1.1.0:databases/R-cran-DBI \
		R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-blob>0:devel/R-cran-blob \
		R-cran-memoise>0:devel/R-cran-memoise \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-plogr>0:devel/R-cran-plogr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
