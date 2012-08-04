# New ports collection makefile for:	fmit
# Date created:		2007-09-08
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fmit
PORTVERSION=	0.99.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/fmit/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Music Instrument Tuner

LICENSE=	GPLv2

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3

OPTIONS_DEFINE=	OSS ALSA PORTAUDIO JACK
OPTIONS_DEFAULT=	OSS JACK

USE_BZIP2=	yes
USE_XORG=	xmu
USE_QT4=	corelib gui opengl \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GL=		glut
USE_CMAKE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOSS}
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_OSS:BOOL=true
.else
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_OSS:BOOL=false
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_ALSA:BOOL=true
.else
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_ALSA:BOOL=false
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
BUILD_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_PORTAUDIO:BOOL=true
.else
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_PORTAUDIO:BOOL=false
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_JACK:BOOL=true
.else
CMAKE_ARGS+=	-DSOUNDSYSTEM_USE_JACK:BOOL=false
.endif

.include <bsd.port.mk>
