PORTNAME=	hackrf
DISTVERSION=	2026.01.1
CATEGORIES=	comms devel hamradio science security
MASTER_SITES=	https://github.com/greatscottgadgets/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	tomek@cedro.info
COMMENT=	Low cost open source hardware software radio platform
WWW=		https://greatscottgadgets.com/hackrf/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float

USES=		cmake tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIBUSB_LIBRARIES=/usr/lib/libusb.so
CMAKE_SOURCE_PATH=	${WRKSRC}/host

CONFLICTS=	hackrf-devel

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
