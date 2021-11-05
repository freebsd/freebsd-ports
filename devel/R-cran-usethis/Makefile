PORTNAME=	usethis
DISTVERSION=	2.0.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Automate Package and Project Setup

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-clipr>=0.3.0:devel/R-cran-clipr \
		R-cran-clisymbols>0:devel/R-cran-clisymbols \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-curl>=2.7:ftp/R-cran-curl \
		R-cran-desc>=1.2.0:devel/R-cran-desc \
		R-cran-fs>=1.3.0:sysutils/R-cran-fs \
		R-cran-gert>=1.0.2:devel/R-cran-gert \
		R-cran-gh>=1.2.0:www/R-cran-gh \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-rappdirs>=0.3.3:devel/R-cran-rappdirs \
		R-cran-rlang>0.4.10:devel/R-cran-rlang \
		R-cran-rprojroot>=1.2:devel/R-cran-rprojroot \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-whisker>0:devel/R-cran-whisker \
		R-cran-withr>=2.3.0:devel/R-cran-withr \
		R-cran-yaml>0:textproc/R-cran-yaml
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
