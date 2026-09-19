PORTNAME=	essentia
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1_beta5-1452
DISTVERSIONSUFFIX=	-g66a890f2
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	ceff6c73e591c078d418a5663491b97a75413b99.patch:-p1 # support for ffmpeg-9.x, https://github.com/MTG/essentia/pull/1546

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for audio and music analysis
WWW=		https://essentia.upf.edu/ \
		https://github.com/MTG/essentia

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libchromaprint.so:audio/chromaprint \
		libfftw3f.so:math/fftw3-float \
		libsamplerate.so:audio/libsamplerate \
		libtag.so:audio/taglib \
		libyaml.so:textproc/libyaml

USES=		compiler:c++11-lib eigen:3 pkgconfig waf

USE_GITHUB=	yes
GH_ACCOUNT=	MTG

.include <bsd.port.mk>
