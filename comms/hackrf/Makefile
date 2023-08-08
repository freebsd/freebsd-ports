PORTNAME=	hackrf
PORTVERSION=	2021.03.1
PORTREVISION=	1
CATEGORIES=	comms devel hamradio science security

MAINTAINER=	tomek@cedro.info
COMMENT=	Low cost open source hardware software radio platform
WWW=		https://greatscottgadgets.com/hackrf/

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float

USES=		cmake
USE_GITHUB=	YES
GH_ACCOUNT=	mossmann
GH_TAGNAME=	e6eb4ba

CONFLICTS=	hackrf-devel

CMAKE_SOURCE_PATH=	${WRKSRC}/host
CMAKE_ARGS=	-DLIBUSB_LIBRARIES=/usr/lib/libusb.so

USE_LDCONFIG=	yes

.include <bsd.port.mk>
