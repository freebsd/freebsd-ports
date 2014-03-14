# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dabstick-radio
PORTVERSION=	0.96
PORTREVISION=	4
CATEGORIES=	comms audio hamradio
MASTER_SITES=	http://www.sdr-j.tk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	DAB/DAB+ and wideband FM receiver for RTL2832-based USB sticks

LICENSE=	GPLv2

LIB_DEPENDS+=	librtlsdr.so:${PORTSDIR}/comms/rtl-sdr \
		libqwt.so:${PORTSDIR}/x11-toolkits/qwt5 \
		libportaudio.so.2:${PORTSDIR}/audio/portaudio2 \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfaad.so:${PORTSDIR}/audio/faad

USE_QT4=	gui qt3support qmake_build moc_build rcc_build uic_build

PORTDOCS=	*
PLIST_FILES+=	bin/dabreceiver bin/fmreceiver bin/spectrum-viewer

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	uses MMX and SSE2

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if (${OSVERSION} >= 901000) && exists(${DESTDIR}/usr/bin/clang)
CC=		clang
CXX=		clang++
CPP=		clang-cpp
.else
USE_GCC=	yes
.endif

do-configure:
	cd ${WRKSRC}/fmreceiver-dab && ${SETENV} ${QMAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS}
	cd ${WRKSRC}/dabreceiver-V2 && ${SETENV} ${QMAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS}
	cd ${WRKSRC}/spectrum-viewer && ${SETENV} ${QMAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS}

do-build:
	cd ${WRKSRC}/fmreceiver-dab && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS}
	cd ${WRKSRC}/dabreceiver-V2 && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS}
	cd ${WRKSRC}/spectrum-viewer && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS}

do-install:
	${INSTALL} ${WRKSRC}/fmreceiver-dab/fmreceiver \
		${WRKSRC}/dabreceiver-V2/dabreceiver \
		${WRKSRC}/spectrum-viewer/spectrum-viewer \
		${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/dabreceiver-V2 ${STAGEDIR}${DOCSDIR}/fmreceiver-dab
	${INSTALL_DATA} ${WRKSRC}/dabreceiver-V2/README ${STAGEDIR}${DOCSDIR}/dabreceiver-V2
	${INSTALL_DATA} ${WRKSRC}/fmreceiver-dab/README ${STAGEDIR}${DOCSDIR}/fmreceiver-dab
.endif

.include <bsd.port.mk>
