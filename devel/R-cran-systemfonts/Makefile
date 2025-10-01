PORTNAME=	systemfonts
DISTVERSION=	1.3.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	einar@isnic.is
COMMENT=	System Native Font Finding
WWW=		https://systemfonts.r-lib.org/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-cpp11>=0.2.1:devel/R-cran-cpp11 \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>0:devel/R-cran-lifecycle
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-farver>0:graphics/R-cran-farver \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-ragg>0:graphics/R-cran-ragg \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=2.1.0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles pkgconfig

pre-test:
	# R-cran-svglite package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("svglite", \
		repos = "https://cloud.r-project.org")'

do-test:
	@${FIND} ${WRKSRC} \( -name '*.o' -o -name '*.so' \) -delete
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${LOCALBASE}/bin/R CMD check --no-manual ${PORTNAME}

.include <bsd.port.mk>
