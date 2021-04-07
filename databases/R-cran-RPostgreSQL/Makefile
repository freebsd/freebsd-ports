PORTNAME=	RPostgreSQL
DISTVERSION=	0.6-2
PORTREVISION=	3
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R Interface to the 'PostgreSQL' Database System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cran:auto-plist,compiles pgsql shebangfix

CRAN_DEPENDS=	R-cran-DBI>=0.3:databases/R-cran-DBI
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

SHEBANG_FILES=	inst/devTests/*.r \
		inst/devTests/*.sh
SHEBANG_LANG=	r
r_OLD_CMD=	/usr/bin/r
r_CMD=		${LOCALBASE}/bin/R

.include <bsd.port.mk>
