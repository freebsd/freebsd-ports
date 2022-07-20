PORTNAME=	sqldf
DISTVERSION=	0.4-11
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	SQL select on R data frames

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-proto>=0.3.9.2_6:devel/R-cran-proto \
		R-cran-chron>=2.3.42:devel/R-cran-chron \
		R-cran-gsubfn>=0.6.4:devel/R-cran-gsubfn \
		R-cran-DBI>=1.1.0:databases/R-cran-DBI \
		R-cran-RSQLite>=2.2.14:databases/R-cran-RSQLite
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
