# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	gqrx
PORTVERSION=	20130504
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Qt-based software defined radio receiver

LICENSE=	GPLv3

LIB_DEPENDS=	libgnuradio-core.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-audio.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-osmosdr.so:${PORTSDIR}/comms/gr-osmosdr \
		libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libpulse-simple.so:${PORTSDIR}/audio/pulseaudio \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libboost_program_options.so:${PORTSDIR}/devel/boost-libs

USES=		pkgconfig qmake
USE_QT4=	moc_build rcc_build uic_build corelib gui svg

PLIST_FILES=	bin/gqrx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqrx ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
