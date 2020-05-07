# $FreeBSD$

PORTNAME=	padthv1
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	0_9_14
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Old-school polyphonic additive synthesizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libjack.so:audio/jack \
		liblo.so:audio/liblo

USES=		autoreconf compiler:c++11-lang gl gmake pkgconfig qt:5 \
		shared-mime-info
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	rncbc
USE_GL=		gl
USE_QT=		core gui widgets xml buildtools_build linguisttools_build qmake_build

CONFIGURE_ARGS=	--disable-alsa-midi

BINARY_ALIAS=	qmake-qt5=${QMAKE}

.include <bsd.port.mk>
