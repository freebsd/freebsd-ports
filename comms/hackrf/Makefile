PORTNAME=	hackrf
PORTVERSION=	2024.02.1
CATEGORIES=	comms devel hamradio science security

MAINTAINER=	tomek@cedro.info
COMMENT=	Low cost open source hardware software radio platform
WWW=		https://greatscottgadgets.com/hackrf/

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libfftw3.so:math/fftw3

USES=		cmake
USE_GITHUB=	YES
GH_ACCOUNT=	greatscottgadgets
GH_TAGNAME=	18b485e

CONFLICTS=	hackrf-devel

CMAKE_SOURCE_PATH=	${WRKSRC}/host
CMAKE_ARGS=	-DLIBUSB_LIBRARIES=/usr/lib/libusb.so

USE_LDCONFIG=	yes

.include <bsd.port.mk>
