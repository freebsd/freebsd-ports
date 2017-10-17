# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dabstick-radio
PORTVERSION=	0.96
PORTREVISION=	12
CATEGORIES=	comms audio hamradio
MASTER_SITES=	http://www.sdr-j.tk/ \
		LOCAL/nox/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DAB/DAB+ and wideband FM receiver for RTL2832-based USB sticks

LICENSE=	GPLv2

LIB_DEPENDS+=	librtlsdr.so:comms/rtl-sdr \
		libqwt.so:x11-toolkits/qwt5 \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libavcodec.so:multimedia/ffmpeg \
		libfftw3.so:math/fftw3 \
		libfaad.so:audio/faad

USES=		tar:tgz
USE_QT4=	gui qt3support qmake_build moc_build rcc_build uic_build

PORTDOCS=	*
PLIST_FILES+=	bin/dabreceiver bin/fmreceiver bin/spectrum-viewer

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	uses MMX and SSE2 instructions

OPTIONS_DEFINE=	DOCS

.if exists(${DESTDIR}/usr/bin/clang)
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
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/dabreceiver-V2 ${STAGEDIR}${DOCSDIR}/fmreceiver-dab
	${INSTALL_DATA} ${WRKSRC}/dabreceiver-V2/README ${STAGEDIR}${DOCSDIR}/dabreceiver-V2
	${INSTALL_DATA} ${WRKSRC}/fmreceiver-dab/README ${STAGEDIR}${DOCSDIR}/fmreceiver-dab

.include <bsd.port.mk>
