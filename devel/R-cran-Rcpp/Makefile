PORTNAME=	Rcpp
DISTVERSION=	1.1.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Seamless R and C++ Integration
WWW=		https://cran.r-project.org/web/packages/Rcpp/

LICENSE=	GPLv2+

USES=		cran:auto-plist,compiles shebangfix
SHEBANG_FILES=	inst/examples/*/*.r inst/examples/*/*.R inst/examples/*/*.sh
SHEBANG_LANG=	r
r_OLD_CMD=	/usr/bin/r
r_CMD=		${LOCALBASE}/bin/R

.include <bsd.port.mk>
