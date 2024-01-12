PORTNAME=	RPostgreSQL
DISTVERSION=	0.7-6
CATEGORIES=	databases
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R Interface to the 'PostgreSQL' Database System
WWW=		https://cran.r-project.org/web/packages/RPostgreSQL/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-DBI>=0.3:databases/R-cran-DBI

USES=		cran:auto-plist,compiles pgsql shebangfix

SHEBANG_FILES=	inst/devTests/*.r inst/devTests/*.sh
SHEBANG_LANG=	r
r_OLD_CMD=	/usr/bin/r
r_CMD=		${LOCALBASE}/bin/R

.include <bsd.port.mk>
