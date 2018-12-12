# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqldf
DISTVERSION=	0.4-7.1
PORTREVISION=	3
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	SQL select on R data frames

LICENSE=	GPLv2

BUILD_DEPENDS=	R-cran-proto>=0.3.9.2_6:devel/R-cran-proto \
		R-cran-chron>=2.3.42:devel/R-cran-chron \
		R-cran-gsubfn>=0.6.4:devel/R-cran-gsubfn \
		R-cran-DBI>=0.2.5_6:databases/R-cran-DBI \
		R-cran-RSQLite>=0.11.1:databases/R-cran-RSQLite \
		R-cran-RSQLite.extfuns>=0.0.1:databases/R-cran-RSQLite.extfuns
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
