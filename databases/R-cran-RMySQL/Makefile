# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	RMySQL
DISTVERSION=	0.10.22
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R interface to the MySQL database

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-DBI>=0.4:databases/R-cran-DBI
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles mysql

.include <bsd.port.mk>
