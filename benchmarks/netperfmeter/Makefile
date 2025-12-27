PORTNAME=	netperfmeter
DISTVERSION=	2.0.0
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.nntb.no/~dreibh/netperfmeter/download/

MAINTAINER=	dreibh@simula.no
COMMENT=	Network Performance Meter
WWW=		https://www.nntb.no/~dreibh/netperfmeter/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm:graphics/GraphicsMagick \
		pdf2svg:graphics/pdf2svg
RUN_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-data.table>0:devel/R-cran-data.table \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-R.utils>0:devel/R-cran-R.utils

USES=		cmake desktop-file-utils ghostscript shebangfix tar:xz

SHEBANG_FILES=	src/pdfembedfonts src/plot-netperfmeter-results \
		src/setpdfmetadata

CMAKE_OFF=	WITH_TEST_PROGRAMS
CMAKE_ON=	WITH_ICONS WITH_PLOT_PROGRAMS

.include <bsd.port.mk>
