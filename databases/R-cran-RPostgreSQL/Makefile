# $FreeBSD$

PORTNAME=	RPostgreSQL
DISTVERSION=	0.6-2
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R Interface to the 'PostgreSQL' Database System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cran:auto-plist,compiles pgsql

CRAN_DEPENDS=	R-cran-DBI>=0.3:databases/R-cran-DBI
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

.include <bsd.port.mk>
