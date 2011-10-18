# New ports collection makefile for:	fmit
# Date created:		2007-09-08
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fmit
PORTVERSION=	0.99.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/fmit/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Music Instrument Tuner

LICENSE=	GPLv2

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3

OPTIONS=	OSS "Enable OSS support" on \
		ALSA "Enable ALSA support" off \
		PORTAUDIO "Enable PortAudio support" off \
		JACK "Enable JACK support" on \

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui opengl \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GL=		glut
USE_CMAKE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if defined(WITHOUT_OSS)
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_OSS:BOOL=false
.else
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_OSS:BOOL=true
.endif

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_ALSA:BOOL=true
.else
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_ALSA:BOOL=false
.endif

.if defined(WITH_PORTAUDIO)
BUILD_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_PORTAUDIO:BOOL=true
.else
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_PORTAUDIO:BOOL=false
.endif

.if defined(WITHOUT_JACK)
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_JACK:BOOL=false
.else
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_JACK:BOOL=true
.endif

.include <bsd.port.mk>
