# Created by: <mr@freebsd.org>
# $FreeBSD$

PORTNAME=	inspectrum
PORTVERSION=	g20180321
#PORTREVISION=	1
#DISTVERSIONPREFIX=	v
CATEGORIES=	comms hamradio

MAINTAINER=	mr@freebsd.org
COMMENT=	Offline radio signal analyser

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libliquid.so:comms/liquid-dsp

CMAKE_INSTALL_PREFIX=   ${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	miek
GH_TAGNAME=	11853b64062bda4f81926613f15d1d9654c227c8

USE_QT5=	core buildtools_build concurrent widgets
USES=		cmake pkgconfig qmake
USE_LDCONFIG=	yes

.include <bsd.port.mk>
