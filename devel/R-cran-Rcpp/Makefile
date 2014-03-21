# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Rcpp
PORTVERSION=	0.11.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Seamless R and C++ Integration

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=	cran:auto-plist shebangfix

SHEBANG_LANG=	r
r_OLD_CMD=	/usr/bin/r
r_CMD=	${LOCALBASE}/bin/R
SHEBANG_FILES=	inst/examples/ConvolveBenchmarks/buildAndRun.sh \
		inst/examples/ConvolveBenchmarks/exampleRCode.r \
		inst/examples/FastLM/*.r \
		inst/examples/Misc/*.r \
		inst/examples/RcppInline/*.r \
		inst/examples/SugarPerformance/sugarBenchmarks.R \
		inst/examples/functionCallback/newApiExample.r

.include <bsd.port.mk>
