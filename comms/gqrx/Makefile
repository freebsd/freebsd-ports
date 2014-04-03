# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	gqrx
PORTVERSION=	20140313
CATEGORIES=	comms hamradio
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Qt-based software defined radio receiver

LICENSE=	GPLv3

LIB_DEPENDS=	libgnuradio-runtime.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-analog.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-blocks.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-filter.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-fft.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-audio.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-osmosdr.so:${PORTSDIR}/comms/gr-osmosdr \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libpulse-simple.so:${PORTSDIR}/audio/pulseaudio \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libboost_program_options.so:${PORTSDIR}/devel/boost-libs

USES=		pkgconfig qmake
USE_QT5=	buildtools core gui svg network widgets

QMAKE_ARGS+=	VER="${PORTVERSION}"

PLIST_FILES=	bin/gqrx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqrx ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
