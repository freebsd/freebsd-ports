# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	gqrx
PORTVERSION=	2.5.3
DISTVERSIONPREFIX=	v
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
		libgnuradio-audio.so:comms/gnuradio \
		libgnuradio-digital.so:comms/gnuradio \
		libgnuradio-pmt.so:comms/gnuradio \
		libgnuradio-osmosdr.so:comms/gr-osmosdr \
		libpulse.so:audio/pulseaudio \
		libpulse-simple.so:audio/pulseaudio

USE_GITHUB=	yes
GH_ACCOUNT=	csete

USES=		pkgconfig qmake

OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	QT4 QT5

QT4_USE=	QT4=corelib,gui,network
QT5_USE=	QT5=buildtools_build,core,gui,svg,network,widgets

OPTIONS_DEFAULT=	QT5

PLIST_FILES=	bin/gqrx share/applications/gqrx.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqrx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gqrx.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.pre.mk>

# Chase comms/gnuradio compiler choice
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
