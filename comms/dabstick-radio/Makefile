# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dabstick-radio
PORTVERSION=	0.96
PORTREVISION=	3
CATEGORIES=	comms audio hamradio
MASTER_SITES=	http://www.sdr-j.tk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	DAB/DAB+ and wideband FM receiver for RTL2832-based USB sticks

LICENSE=	GPLv2

LIB_DEPENDS+=	rtlsdr:${PORTSDIR}/comms/rtl-sdr \
		qwt:${PORTSDIR}/x11-toolkits/qwt5 \
		portaudio.2:${PORTSDIR}/audio/portaudio2 \
		sndfile:${PORTSDIR}/audio/libsndfile \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		fftw3:${PORTSDIR}/math/fftw3 \
		faad:${PORTSDIR}/audio/faad

USE_QT4=	gui qt3support qmake_build moc_build rcc_build uic_build

QMAKE_DABSTICK=	${QMAKE} -unix PREFIX=${PREFIX} -o

PORTDOCS=	*
PLIST_FILES+=	bin/dabreceiver bin/fmreceiver bin/spectrum-viewer

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	uses MMX and SSE2

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if (${OSVERSION} >= 901000) && exists(${DESTDIR}/usr/bin/clang)
CC=		clang
CXX=		clang++
CPP=		clang-cpp
.else
USE_GCC=	yes
.endif

do-configure:
	cd ${WRKSRC}/fmreceiver-dab && ${SETENV} ${MAKE_ENV} \
		${QMAKE_DABSTICK} Makefile fmreceiver.pro
	cd ${WRKSRC}/dabreceiver-V2 && ${SETENV} ${MAKE_ENV} \
		${QMAKE_DABSTICK} Makefile dabreceiver.pro
	cd ${WRKSRC}/spectrum-viewer && ${SETENV} ${MAKE_ENV} \
		${QMAKE_DABSTICK} Makefile spectrum-viewer.pro

do-build:
	cd ${WRKSRC}/fmreceiver-dab && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS} CC=${CC} CXX=${CXX} LINK=${CXX}
	cd ${WRKSRC}/dabreceiver-V2 && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS} CC=${CC} CXX=${CXX} LINK=${CXX}
	cd ${WRKSRC}/spectrum-viewer && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS} CC=${CC} CXX=${CXX} LINK=${CXX}

do-install:
	${INSTALL} ${WRKSRC}/fmreceiver-dab/fmreceiver \
		${WRKSRC}/dabreceiver-V2/dabreceiver \
		${WRKSRC}/spectrum-viewer/spectrum-viewer \
		${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/dabreceiver-V2 ${DOCSDIR}/fmreceiver-dab
	${INSTALL_DATA} ${WRKSRC}/dabreceiver-V2/README ${DOCSDIR}/dabreceiver-V2
	${INSTALL_DATA} ${WRKSRC}/fmreceiver-dab/README ${DOCSDIR}/fmreceiver-dab
.endif

.include <bsd.port.mk>
