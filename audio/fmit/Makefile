# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fmit
PORTVERSION=	1.2.6
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Free Music Instrument Tuner

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		gl gnome pkgconfig qmake qt:5 tar:bzip2

USE_QT=		buildtools core gui opengl qmake_build multimedia network svg widgets
USE_GL=		gl glut
QMAKE_ARGS+=	PREFIXSHORTCUT=${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	gillesdegottex

OPTIONS_DEFINE=	ALSA JACK OSS PORTAUDIO
OPTIONS_DEFAULT=	JACK OSS

OPTIONS_SUB=	yes

ALSA_LIB_DEPENDS=	libasound.so.2:audio/alsa-lib
ALSA_CMAKE_ON=		-DSOUNDSYSTEM_USE_ALSA:BOOL=true
ALSA_CMAKE_OFF=		-DSOUNDSYSTEM_USE_ALSA:BOOL=false

OSS_CMAKE_ON=		-DSOUNDSYSTEM_USE_OSS:BOOL=true
OSS_CMAKE_OFF=		-DSOUNDSYSTEM_USE_OSS:BOOL=false

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_ON=		-DSOUNDSYSTEM_USE_JACK:BOOL=true
JACK_CMAKE_OFF=		-DSOUNDSYSTEM_USE_JACK:BOOL=false

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_ON=	-DSOUNDSYSTEM_USE_PORTAUDIO:BOOL=true
PORTAUDIO_CMAKE_OFF=	-DSOUNDSYSTEM_USE_PORTAUDIO:BOOL=false

.include <bsd.port.mk>
