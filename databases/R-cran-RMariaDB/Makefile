PORTNAME=	RMariaDB
DISTVERSION=	1.3.5
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	chris.longros@gmail.com
COMMENT=	DBI interface to MariaDB and MySQL using cpp11
WWW=		https://cran.r-project.org/package=RMariaDB

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-blob>0:devel/R-cran-blob \
		R-cran-cpp11>0:devel/R-cran-cpp11 \
		R-cran-DBI>=1.1.3:databases/R-cran-DBI \
		R-cran-hms>=0.5.0:devel/R-cran-hms \
		R-cran-lubridate>0:devel/R-cran-lubridate \
		R-cran-rlang>0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles mysql

.include <bsd.port.mk>
