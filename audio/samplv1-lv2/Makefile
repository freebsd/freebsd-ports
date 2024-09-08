PORTNAME=	samplv1
DISTVERSION=	1.1.0
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Old-school polyphonic sampler
WWW=		https://samplv1.sourceforge.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		liblo.so:audio/liblo \
		libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++17-lang desktop-file-utils gl localbase pkgconfig qt:6 \
		shared-mime-info
USE_QT=		base svg tools:build
USE_GL=		gl

PLIST_SUB=	SHL3=${PORTVERSION} SHL2=${PORTVERSION:R}

CMAKE_OFF=	CONFIG_ALSA_MIDI

.include <bsd.port.mk>
