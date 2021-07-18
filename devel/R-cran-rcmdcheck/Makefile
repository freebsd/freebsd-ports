PORTNAME=	rcmdcheck
DISTVERSION=	1.3.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Run 'R CMD check' from 'R' and Capture Results

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-callr>=3.1.1.9000:devel/R-cran-callr \
		R-cran-cli>=1.1.0:devel/R-cran-cli \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-desc>=1.2.0:devel/R-cran-desc \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-pkgbuild>0:devel/R-cran-pkgbuild \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-sessioninfo>0:devel/R-cran-sessioninfo \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-xopen>0:sysutils/R-cran-xopen
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
