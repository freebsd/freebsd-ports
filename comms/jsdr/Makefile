# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsdr
PORTVERSION=	4.1
CATEGORIES=	comms audio hamradio
MASTER_SITES=	http://www.sdr-j.tk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	SDR tools for RTL2832-based USB sticks

LICENSE=	GPLv2

LIB_DEPENDS+=	qwt:${PORTSDIR}/x11-toolkits/qwt5 \
		portaudio.2:${PORTSDIR}/audio/portaudio2 \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		sndfile:${PORTSDIR}/audio/libsndfile \
		fftw3:${PORTSDIR}/math/fftw3

USE_QT4=	gui qt3support qmake_build moc_build rcc_build uic_build

QMAKE_DABSTICK=	${QMAKE} -unix PREFIX=${PREFIX} -o

PORTDOCS=	*
PLIST_FILES+=	bin/swreceiver bin/spectrum-viewer-${PORTVERSION} \
		bin/mini-receiver bin/fmreceiver-${PORTVERSION}

.include <bsd.port.pre.mk>

do-configure:
	cd ${WRKSRC}/make-x64/swreceiver && ${SETENV} ${MAKE_ENV} \
		${QMAKE_DABSTICK} Makefile swreceiver.pro
	cd ${WRKSRC}/make-x64/fmreceiver && ${SETENV} ${MAKE_ENV} \
		${QMAKE_DABSTICK} Makefile fmreceiver.pro
	cd ${WRKSRC}/make-x64/spectrum-viewer && ${SETENV} ${MAKE_ENV} \
		${QMAKE_DABSTICK} Makefile spectrum-viewer.pro
	cd ${WRKSRC}/make-x64/mini-receiver && ${SETENV} ${MAKE_ENV} \
		${QMAKE_DABSTICK} Makefile mini-receiver.pro

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
		${PREFIX}/bin
	${INSTALL} ${WRKSRC}/make-x64/spectrum-viewer/spectrum-viewer \
		${PREFIX}/bin/spectrum-viewer-${PORTVERSION}
	${INSTALL} ${WRKSRC}/make-x64/fmreceiver/fmreceiver \
		${PREFIX}/bin/fmreceiver-${PORTVERSION}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
