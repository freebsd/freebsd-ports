# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fmit
PORTVERSION=	1.2.6
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Free Music Instrument Tuner

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING_GPL.txt
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING_LGPL.txt

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		gl gnome pkgconfig qmake qt:5 tar:bzip2

USE_QT=		buildtools_build core gui opengl qmake_build multimedia network svg widgets
USE_GL=		gl glut

USE_GITHUB=	yes
GH_ACCOUNT=	gillesdegottex

QMAKE_ARGS+=	PREFIXSHORTCUT=${PREFIX}

OPTIONS_DEFINE=		ALSA JACK OSS PORTAUDIO
OPTIONS_DEFAULT=	JACK OSS

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_QMAKE_ON=		CONFIG+=acs_alsa

OSS_QMAKE_ON=		CONFIG+=acs_oss

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_QMAKE_ON=		CONFIG+=acs_jack

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_QMAKE_ON=	CONFIG+=acs_portaudio

.include <bsd.port.mk>
