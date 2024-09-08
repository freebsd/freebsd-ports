PORTNAME=	padthv1
DISTVERSION=	1.1.0
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Old-school polyphonic additive synthesizer
WWW=		https://padthv1.sourceforge.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		liblo.so:audio/liblo

USES=		cmake compiler:c++17-lang desktop-file-utils gl localbase pkgconfig qt:6 \
		shared-mime-info
USE_QT=		base svg tools:build
USE_GL=		gl

CMAKE_OFF=	CONFIG_ALSA_MIDI

.include <bsd.port.mk>
