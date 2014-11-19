# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	gqrx
PORTVERSION=	2.3.1
PORTEPOCH=	1
CATEGORIES=	comms hamradio

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Software defined radio receiver powered by GNU Radio and Qt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnuradio-runtime.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-analog.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-blocks.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-filter.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-fft.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-audio.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-osmosdr.so:${PORTSDIR}/comms/gr-osmosdr \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libpulse-simple.so:${PORTSDIR}/audio/pulseaudio

USE_GITHUB=	yes
GH_ACCOUNT=	csete
GH_COMMIT=	4d90b84
GH_TAGNAME=	v${PORTVERSION}

USES=		pkgconfig qmake
USE_QT5=	buildtools_build core gui svg network widgets

PLIST_FILES=	bin/gqrx share/applications/gqrx.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqrx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gqrx.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
