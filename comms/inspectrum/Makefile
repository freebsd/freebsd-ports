# Created by: <mr@freebsd.org>
# $FreeBSD$

PORTNAME=	inspectrum
PORTVERSION=	g20181201
PORTREVISION=	1
#DISTVERSIONPREFIX=	v
CATEGORIES=	comms hamradio

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Offline radio signal analyser

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libliquid.so:comms/liquid-dsp

CMAKE_INSTALL_PREFIX=   ${STAGEDIR}${PREFIX}

USES=		cmake compiler:c++11-lang pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	miek
GH_TAGNAME=	cd115c22cf4d8d7d3ed18e549d6569abf71fa32c

USE_QT=		core buildtools_build concurrent widgets
USE_LDCONFIG=	yes

.include <bsd.port.mk>
