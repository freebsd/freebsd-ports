PORTNAME=	netperfmeter
DISTVERSION=	1.9.7
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.nntb.no/~dreibh/${PORTNAME}/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	Network Performance Meter
WWW=		https://www.nntb.no/~dreibh/netperfmeter/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake shebangfix tar:xz

SHEBANG_FILES=	src/pdfembedfonts src/setpdfmetadata src/plot-netperfmeter-results

CMAKE_OFF=	WITH_NEAT BUILD_TEST_PROGRAMS
CMAKE_ON=	BUILD_PLOT_PROGRAMS

.include <bsd.port.mk>
