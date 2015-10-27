# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	gqrx
PORTVERSION=	2.3.2
DISTVERSIONPREFIX=	v
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
