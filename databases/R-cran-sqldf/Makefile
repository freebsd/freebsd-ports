# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqldf
DISTVERSION=	0.4-6.4
PORTREVISION=	4
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	SQL select on R data frames

LICENSE=	GPLv2

BUILD_DEPENDS=	R-cran-proto>=0.3.9.2_6:${PORTSDIR}/devel/R-cran-proto \
		R-cran-chron>=2.3.42:${PORTSDIR}/devel/R-cran-chron \
		R-cran-gsubfn>=0.6.4:${PORTSDIR}/devel/R-cran-gsubfn \
		R-cran-DBI>=0.2.5_6:${PORTSDIR}/databases/R-cran-DBI \
		R-cran-RSQLite>=0.11.1:${PORTSDIR}/databases/R-cran-RSQLite \
		R-cran-RSQLite.extfuns>=0.0.1:${PORTSDIR}/databases/R-cran-RSQLite.extfuns
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
