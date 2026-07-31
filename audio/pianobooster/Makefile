PORTNAME=	pianobooster
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-92
DISTVERSIONSUFFIX=	-g6dafdcb
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI file player that teaches how to play the piano
WWW=		https://www.pianobooster.org/index.html \
		https://github.com/pianobooster/PianoBooster

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gplv3.txt

LIB_DEPENDS=	libftgl.so:graphics/ftgl \
		libjack.so:audio/jack \
		librtmidi.so:audio/rtmidi

USES=		cmake compiler:c++11-lang desktop-file-utils gl pkgconfig qt:6
USE_QT=		5compat base tools:build
USE_GL=		gl glu

USE_GITHUB=	yes
GH_ACCOUNT=	pianobooster
GH_PROJECT=	PianoBooster

CMAKE_ON=	USE_JACK
CMAKE_OFF=	USE_BUNDLED_RTMIDI
CMAKE_ARGS=	-DQT_PACKAGE_NAME=Qt6 \
		-DDATA_DIR:STRING=share/${PORTNAME}

OPTIONS_DEFINE=		FLUIDSYNTH
OPTIONS_DEFAULT=	FLUIDSYNTH

FLUIDSYNTH_CMAKE_BOOL=	EXPERIMENTAL_USE_FLUIDSYNTH
FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

post-stage:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
