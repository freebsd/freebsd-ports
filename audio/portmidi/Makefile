PORTNAME=	portmidi
DISTVERSIONPREFIX=v
DISTVERSION=	2.0.8
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Library for real time MIDI input and output
WWW=		https://github.com/PortMidi

LICENSE=	PL
LICENSE_NAME=	PortMidi license
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake dos2unix localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	PortMidi

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	ALSA SNDIO
OPTIONS_DEFAULT=	ALSA

BACKEND_DESC=	MIDI sequencer backend

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-seq-server>0:audio/alsa-seq-server

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	USE_SNDIO

.include <bsd.port.mk>
