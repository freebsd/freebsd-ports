# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	RMySQL
DISTVERSION=	0.10.23
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R interface to the MySQL database

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-DBI>=0.4:databases/R-cran-DBI
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cpe cran:auto-plist,compiles mysql

CPE_VENDOR=	r-consortium

.include <bsd.port.mk>
