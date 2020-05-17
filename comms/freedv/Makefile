# $FreeBSD$

PORTNAME=	freedv
DISTVERSION=	1.3.1
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	https://hobbes1069.fedorapeople.org/freetel/freedv/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Narrow band digital voice

LICENSE=	LGPL21

LIB_DEPENDS=	libcodec2.so:audio/codec2 \
		libportaudio.so:audio/portaudio \
		libhamlib.so:comms/hamlib \
		libsamplerate.so:audio/libsamplerate \
		libsox.so:audio/sox \
		libsndfile.so:audio/libsndfile \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp

USES=		cmake compiler:c++11-lib gnome tar:xz
USE_WX=		3.0+
CMAKE_ARGS+=	-DCODEC2_INCLUDE_DIRS=${LOCALBASE}/include/codec2 \
		-DCODEC2_LIBRARY=${LOCALBASE}/lib/libcodec2.so \
		-DUSE_STATIC_CODEC2=FALSE \
		-DUSE_STATIC_PORTAUDIO=FALSE \
		-DUSE_STATIC_SOX=FALSE \
		-DUSE_STATIC_SPEEXDSP=FALSE
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
