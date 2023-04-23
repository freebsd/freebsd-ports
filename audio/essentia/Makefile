PORTNAME=	essentia
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1_beta5-859
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gb247091f
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for audio and music analysis
WWW=		https://essentia.upf.edu/

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

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libessentia.so

.include <bsd.port.mk>
