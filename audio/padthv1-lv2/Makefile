# $FreeBSD$

PORTNAME=	padthv1
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	0_9_21
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Old-school polyphonic additive synthesizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		liblo.so:audio/liblo

USES=		cmake compiler:c++17-lang gl pkgconfig qt:5 \
		shared-mime-info
USE_GL=		gl
USE_QT=		core gui widgets xml buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	rncbc

CMAKE_OFF=	CONFIG_ALSA_MIDI

.include <bsd.port.mk>
