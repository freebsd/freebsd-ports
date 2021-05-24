# Created by: Guangyuan Yang <ygy@FreeBSD.org>

PORTNAME=	pkgcache
DISTVERSION=	1.2.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Cache 'CRAN'-Like Metadata and R Packages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-callr>=2.0.4.9000:devel/R-cran-callr \
		R-cran-cli>=2.0.0:devel/R-cran-cli \
		R-cran-filelock>0:devel/R-cran-filelock \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-rappdirs>0:devel/R-cran-rappdirs \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-uuid>0:devel/R-cran-uuid \
		R-cran-curl>=3.2:ftp/R-cran-curl \
		R-cran-assertthat>0:math/R-cran-assertthat \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-processx>=3.3.0.9001:sysutils/R-cran-processx
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-sessioninfo>0:devel/R-cran-sessioninfo \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-fs>0:sysutils/R-cran-fs

USES=		cran:auto-plist

.include <bsd.port.mk>
