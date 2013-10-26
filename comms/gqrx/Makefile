# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	gqrx
PORTVERSION=	20130504
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Qt-based software defined radio receiver

LICENSE=	GPLv3

LIB_DEPENDS=	gnuradio-core:${PORTSDIR}/comms/gnuradio \
		gnuradio-audio:${PORTSDIR}/comms/gnuradio \
		gnuradio-osmosdr:${PORTSDIR}/comms/gr-osmosdr \
		pulse:${PORTSDIR}/audio/pulseaudio \
		pulse-simple:${PORTSDIR}/audio/pulseaudio \
		boost_system:${PORTSDIR}/devel/boost-libs \
		boost_program_options:${PORTSDIR}/devel/boost-libs

USES=	pkgconfig
USE_QT4=	qmake_build moc_build rcc_build uic_build corelib gui svg

PLIST_FILES=	bin/gqrx

NO_STAGE=	yes
do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqrx ${PREFIX}/bin

.include <bsd.port.mk>
