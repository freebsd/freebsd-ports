PORTNAME=	pkgcache
DISTVERSION=	2.0.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Cache 'CRAN'-Like Metadata and R Packages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-callr>=2.0.4.9000:devel/R-cran-callr \
		R-cran-cli>=3.2.0:devel/R-cran-cli \
		R-cran-filelock>0:devel/R-cran-filelock \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-rappdirs>0:devel/R-cran-rappdirs \
		R-cran-curl>=3.2:ftp/R-cran-curl \
		R-cran-processx>=3.3.0.9001:sysutils/R-cran-processx
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-pillar>0:devel/R-cran-pillar \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-sessioninfo>0:devel/R-cran-sessioninfo \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-pingr>0:net/R-cran-pingr \
		R-cran-fs>0:sysutils/R-cran-fs \
		R-cran-spelling>0:textproc/R-cran-spelling

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
