# Created by: <mr@freebsd.org>
# $FreeBSD$

PORTNAME=	inspectrum
PORTVERSION=	g20191102
#PORTREVISION=	2
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
GH_TAGNAME=	d6115cb458068fa64c7bbd9020bcbab3373fee0e

USE_QT=		core buildtools_build concurrent widgets
USE_LDCONFIG=	yes

.include <bsd.port.mk>
