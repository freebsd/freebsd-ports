PORTNAME=	netperfmeter
DISTVERSION=	2.0.8
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.nntb.no/~dreibh/netperfmeter/download/

MAINTAINER=	dreibh@simula.no
COMMENT=	Network Performance Meter
WWW=		https://www.nntb.no/~dreibh/netperfmeter/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake shared-mime-info shebangfix tar:xz

SHEBANG_FILES=	src/pdfembedfonts src/plot-netperfmeter-results \
		src/setpdfmetadata

# Work-around for build issue on ARM:
# https://bugs.freebsd.org/285706 https://bugs.freebsd.org/292237
MAKE_ENV=	OMP_NUM_THREADS=1

OPTIONS_DEFINE=			ICONS \
				PLOT_PROGRAMS \
				EXAMPLE_SCRIPTS \
				EXAMPLE_RESULTS

OPTIONS_DEFAULT=		${OPTIONS_DEFINE}
OPTIONS_SUB=			yes

EXAMPLE_RESULTS_DESC=		Include example results
EXAMPLE_SCRIPTS_DESC=		Include example scripts
ICONS_DESC=			Include icons
PLOT_PROGRAMS_DESC=		Include plot programs

EXAMPLE_RESULTS_CMAKE_BOOL=	WITH_EXAMPLE_RESULTS

EXAMPLE_SCRIPTS_CMAKE_BOOL=	WITH_EXAMPLE_SCRIPTS

ICONS_BUILD_DEPENDS=		gm:graphics/GraphicsMagick \
				mutool:graphics/mupdf
ICONS_USES=			ghostscript
ICONS_CMAKE_BOOL=		WITH_ICONS

PLOT_PROGRAMS_RUN_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
				R-cran-data.table>0:devel/R-cran-data.table \
				R-cran-dplyr>0:math/R-cran-dplyr \
				R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
				R-cran-R.utils>0:devel/R-cran-R.utils
PLOT_PROGRAMS_CMAKE_BOOL=	WITH_PLOT_PROGRAMS

.include <bsd.port.mk>
