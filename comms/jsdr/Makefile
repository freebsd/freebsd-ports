# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsdr
PORTVERSION=	4.1
PORTREVISION=	4
CATEGORIES=	comms audio hamradio
MASTER_SITES=	http://www.sdr-j.tk/ \
		LOCAL/nox/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDR tools for RTL2832-based USB sticks

LICENSE=	GPLv2

LIB_DEPENDS+=	libqwt.so:x11-toolkits/qwt5 \
		libportaudio.so:audio/portaudio \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libfftw3.so:math/fftw3

USES=		qmake tar:tgz
USE_QT4=	gui qt3support qmake_build moc_build rcc_build uic_build

PORTDOCS=	*
PLIST_FILES+=	bin/swreceiver bin/spectrum-viewer \
		bin/mini-receiver bin/fmreceiver

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
