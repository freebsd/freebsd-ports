# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	gqrx
PORTVERSION=	2.11.5
DISTVERSIONPREFIX=	v
PORTREVISION=	12
PORTEPOCH=	1
CATEGORIES=	comms hamradio

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Software defined radio receiver powered by GNU Radio and Qt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnuradio-runtime.so:comms/gnuradio \
		libgnuradio-analog.so:comms/gnuradio \
		libgnuradio-blocks.so:comms/gnuradio \
		libgnuradio-filter.so:comms/gnuradio \
		libgnuradio-fft.so:comms/gnuradio \
		libgnuradio-digital.so:comms/gnuradio \
		libgnuradio-pmt.so:comms/gnuradio \
		libgnuradio-osmosdr.so:comms/gr-osmosdr \
		libboost_system.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		liblog4cpp.so:devel/log4cpp \
		libgmpxx.so:math/gmp \
		libgmp.so:math/gmp

USES=		gl pkgconfig qmake qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	csete
USE_GL=		gl
USE_QT=		buildtools_build core gui svg network widgets

OPTIONS_RADIO=	AUDIO
AUDIO_DESC=	Audio backend
OPTIONS_RADIO_AUDIO=	PULSEAUDIO PORTAUDIO GRAUDIO
OPTIONS_DEFAULT=	AUDIO PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
			libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_QMAKE_ON=	AUDIO_BACKEND=pulseaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_QMAKE_ON=	AUDIO_BACKEND=portaudio
GRAUDIO_LIB_DEPENDS=	libgnuradio-audio.so:comms/gnuradio
GRAUDIO_QMAKE_ON=	AUDIO_BACKEND=gr-audio
GRAUDIO_DESC=	GNU Radio audio library support

PLIST_FILES=	bin/gqrx share/applications/gqrx.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqrx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gqrx.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
