# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fmit
PORTVERSION=	0.99.5
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/fmit/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Free Music Instrument Tuner

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3

USE_XORG=	xmu
USE_QT4=	corelib gui opengl \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GL=		glut
USES=		cmake pkgconfig tar:bzip2
INSTALLS_ICONS=	yes

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
