# Created by: mathias.picker@gmx.de
# $FreeBSD$

PORTNAME=	rubberband
DISTVERSION=	1.8.2
CATEGORIES=	audio
MASTER_SITES=	https://breakfastquay.com/files/releases/

PATCH_SITES=	https://github.com/breakfastquay/${PORTNAME}/commit/
PATCHFILES=	03202fa4749c0b4e264f2115bb49028267e2a572.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio time-stretching and pitch-shifting library and utility program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ladspa>0:audio/ladspa \
		lv2>0:audio/lv2
LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate \
		libvamp-sdk.so:audio/vamp-plugin-sdk \
		libfftw3.so:math/fftw3

USES=		gmake pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
