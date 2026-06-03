PORTNAME=	RPostgres
DISTVERSION=	1.4.10
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	chris.longros@gmail.com
COMMENT=	C++ interface to PostgreSQL using cpp11
WWW=		https://cran.r-project.org/package=RPostgres

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-blob>=1.2.0:devel/R-cran-blob \
		R-cran-cpp11>0:devel/R-cran-cpp11 \
		R-cran-DBI>=1.2.0:databases/R-cran-DBI \
		R-cran-hms>=1.0.0:devel/R-cran-hms \
		R-cran-lubridate>0:devel/R-cran-lubridate \
		R-cran-withr>0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles pgsql

.include <bsd.port.mk>
