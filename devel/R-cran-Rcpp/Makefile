PORTNAME=	Rcpp
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Seamless R and C++ Integration
WWW=		https://cran.r-project.org/web/packages/Rcpp/

LICENSE=	GPLv2+

USES=		cran:auto-plist,compiles shebangfix
SHEBANG_FILES=	inst/examples/*/*.r inst/examples/*/*.R inst/examples/*/*.sh \
		inst/discovery/cxx0x.R
SHEBANG_LANG=	r rscript
r_OLD_CMD=	/usr/bin/r
r_CMD=		${LOCALBASE}/bin/R
rscript_OLD_CMD=	"/bin/env Rscript"
rscript_CMD=		${LOCALBASE}/bin/Rscript

.include <bsd.port.mk>
