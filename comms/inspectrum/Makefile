PORTNAME=	inspectrum
DISTVERSIONPREFIX=     v
PORTVERSION=   0.2.3
CATEGORIES=	comms hamradio

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Offline radio signal analyser
WWW=		https://github.com/miek/inspectrum

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libliquid.so:comms/liquid-dsp

CMAKE_INSTALL_PREFIX=	${STAGEDIR}${PREFIX}

USES=		cmake compiler:c++11-lang pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	miek
#GH_TAGNAME=	d6115cb458068fa64c7bbd9020bcbab3373fee0e

USE_QT=		core buildtools:build concurrent gui widgets
USE_LDCONFIG=	yes

.include <bsd.port.mk>
