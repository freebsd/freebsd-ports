# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsdr
PORTVERSION=	4.1
PORTREVISION=	3
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

USES=		tar:tgz
USE_QT4=	gui qt3support qmake_build moc_build rcc_build uic_build

PORTDOCS=	*
PLIST_FILES+=	bin/swreceiver bin/spectrum-viewer-${PORTVERSION} \
		bin/mini-receiver bin/fmreceiver-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

do-configure:
	cd ${WRKSRC}/make-x64/swreceiver && ${SETENV} ${MAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS}
	cd ${WRKSRC}/make-x64/fmreceiver && ${SETENV} ${MAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS}
	cd ${WRKSRC}/make-x64/spectrum-viewer && ${SETENV} ${MAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS}
	cd ${WRKSRC}/make-x64/mini-receiver && ${SETENV} ${MAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS}

do-build:
	cd ${WRKSRC}/make-x64/swreceiver && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS}
	cd ${WRKSRC}/make-x64/fmreceiver && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS}
	cd ${WRKSRC}/make-x64/spectrum-viewer && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS}
	cd ${WRKSRC}/make-x64/mini-receiver && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS}

do-install:
	${INSTALL} ${WRKSRC}/make-x64/swreceiver/swreceiver \
		${WRKSRC}/make-x64/mini-receiver/mini-receiver \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL} ${WRKSRC}/make-x64/spectrum-viewer/spectrum-viewer \
		${STAGEDIR}${PREFIX}/bin/spectrum-viewer-${PORTVERSION}
	${INSTALL} ${WRKSRC}/make-x64/fmreceiver/fmreceiver \
		${STAGEDIR}${PREFIX}/bin/fmreceiver-${PORTVERSION}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
