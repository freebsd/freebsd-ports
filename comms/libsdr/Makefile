# Created by: Jeffrey Baitis <jeff@baitis.net>
# $FreeBSD$

PORTNAME=	libsdr
PORTVERSION=	0.1.0
CATEGORIES=	comms hamradio

MAINTAINER=	jeff@baitis.net
COMMENT=	Simple software defined radio (SDR) library

LICENSE=	GPLv2

LIB_DEPENDS=	libportaudio.so:audio/portaudio \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		librtlsdr.so:comms/rtl-sdr

USE_GITHUB=	yes
GH_ACCOUNT=	hmatuschek
GH_PROJECT=	libsdr
GH_TAGNAME=	0982a68

MAKE_JOBS_UNSAFE=	yes
USES=		cmake pkgconfig
CMAKE_ARGS+=-DCMAKE_BUILD_TYPE=RELEASE
CMAKE_VERBOSE=	1
USE_LDCONFIG=	yes

.include <bsd.port.mk>
