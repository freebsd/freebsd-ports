PORTNAME=	hackrf
PORTVERSION=	g${GIT_SRC_DATE}
PORTREVISION=	1
CATEGORIES=	comms devel hamradio science security
PKGNAMESUFFIX=	-devel

MAINTAINER=	mr@freebsd.org
COMMENT=	Low cost open source hardware software radio platform

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float

CONFLICTS=	hackrf

USE_GITHUB=	YES
GH_ACCOUNT=	mossmann
GH_TAGNAME=	${GIT_SRC_HASH}

USES=		cmake
CMAKE_SOURCE_PATH=	${WRKSRC}/host
CMAKE_ARGS=	-DLIBUSB_LIBRARIES=/usr/lib/libusb.so

USE_LDCONFIG=	yes

.include "Makefile.git_rev"

.include <bsd.port.mk>
