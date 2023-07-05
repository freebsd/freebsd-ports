PORTNAME=	pkgbuild
DISTVERSION=	1.4.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Find Tools Needed to Build R Packages
WWW=		https://github.com/r-lib/pkgbuild

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-R6>0:devel/R-cran-R6 \
		R-cran-callr>=3.2.0:devel/R-cran-callr \
		R-cran-cli>=3.4.0:devel/R-cran-cli \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-processx>0:sysutils/R-cran-processx
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr

USES=		cran:auto-plist

.include <bsd.port.mk>
