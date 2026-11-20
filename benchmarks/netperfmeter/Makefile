PORTNAME=	netperfmeter
DISTVERSION=	2.0.16
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.nntb.no/~dreibh/netperfmeter/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	Network Performance Meter
WWW=		https://www.nntb.no/~dreibh/netperfmeter/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		getopt>=0:misc/getopt
TEST_DEPENDS=	bash:shells/bash \
		getopt>=0:misc/getopt \
		p5-PDF-API2>=0:textproc/p5-PDF-API2 \
		qpdf:print/qpdf

USES=		cmake:testing ghostscript perl5 shared-mime-info \
		shebangfix tar:xz
USE_PERL5=	test

SHEBANG_FILES=	src/netperfmeter-module-loader \
		src/pdfembedfonts \
		src/plot-netperfmeter-results \
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
				pdf2svg:graphics/pdf2svg
ICONS_USES=			ghostscript:build
ICONS_CMAKE_BOOL=		WITH_ICONS

PLOT_PROGRAMS_RUN_DEPENDS=	R-cran-data.table>0:devel/R-cran-data.table \
				R-cran-dplyr>0:math/R-cran-dplyr \
				R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
				p5-PDF-API2>=0:textproc/p5-PDF-API2 \
				qpdf:print/qpdf
PLOT_PROGRAMS_CMAKE_BOOL=	WITH_PLOT_PROGRAMS

.include <bsd.port.mk>
