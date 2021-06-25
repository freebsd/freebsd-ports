# Created by: mathias.picker@gmx.de

PORTNAME=	rubberband
DISTVERSION=	1.9.2
CATEGORIES=	audio
MASTER_SITES=	https://breakfastquay.com/files/releases/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Audio time-stretching and pitch-shifting library and utility program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ladspa>0:audio/ladspa \
		lv2>0:audio/lv2
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libvamp-sdk.so:audio/vamp-plugin-sdk

USES=		localbase meson pkgconfig tar:bzip2
USE_LDCONFIG=	yes

MESON_ARGS=	-Dfft=fftw \
		-Dresampler=libsamplerate

.include <bsd.port.mk>
