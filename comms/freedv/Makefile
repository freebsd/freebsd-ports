PORTNAME=	freedv
DISTVERSIONPREFIX=v
DISTVERSION=	1.7.0
PORTREVISION=	5
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Narrow band digital voice
WWW=		https://freedv.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libcodec2.so:audio/codec2 \
		libportaudio.so:audio/portaudio \
		libgsm.so:audio/gsm \
		libhamlib.so:comms/hamlib \
		libsamplerate.so:audio/libsamplerate \
		libsox.so:audio/sox \
		libsndfile.so:audio/libsndfile \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		liblpcnetfreedv.so:audio/lpcnet

USES=	cmake compiler:c++11-lib pkgconfig tar:xz
USE_WX=	3.0+
USE_GITHUB=	yes
GH_ACCOUNT=	drowe67
GH_PROJECT=	freedv-gui

CMAKE_ARGS=	-DUSE_STATIC_CODEC2=FALSE \
		-DUSE_STATIC_PORTAUDIO=FALSE \
		-DUSE_STATIC_SOX=FALSE \
		-DUSE_STATIC_SPEEXDSP=FALSE

.include <bsd.port.mk>
