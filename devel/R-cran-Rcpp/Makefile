# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Rcpp
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Seamless R and C++ Integration

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		cran:auto-plist shebangfix
SHEBANG_FILES=	inst/examples/ConvolveBenchmarks/buildAndRun.sh \
		inst/examples/*/*.r \
		inst/examples/SugarPerformance/sugarBenchmarks.R
SHEBANG_LANG=	r
r_OLD_CMD=	/usr/bin/r
r_CMD=		${LOCALBASE}/bin/R

.include <bsd.port.mk>
