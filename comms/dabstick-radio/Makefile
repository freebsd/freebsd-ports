# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dabstick-radio
PORTVERSION=	0.92
CATEGORIES=	comms audio hamradio
MASTER_SITES=	http://www.sdr-j.tk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	DAB/DAB+ and wideband FM receiver for RTL2832-based USB sticks

LICENSE=	GPLv2

LIB_DEPENDS+=	rtlsdr:${PORTSDIR}/comms/rtl-sdr \
		qwt:${PORTSDIR}/x11-toolkits/qwt5 \
		portaudio.2:${PORTSDIR}/audio/portaudio2 \
		avcodec${FFMPEG_SUFFIX}:${PORTSDIR}/multimedia/ffmpeg${FFMPEG_SUFFIX} \
		fftw3:${PORTSDIR}/math/fftw3 \
		faad:${PORTSDIR}/audio/faad

USE_QT4=	gui qt3support qmake_build moc_build rcc_build uic_build

FFMPEG_SUFFIX=	1

QMAKE_DABSTICK=	${QMAKE} -unix PREFIX=${PREFIX} -o
MAKE_ENV+=	FFMPEG_SUFFIX=${FFMPEG_SUFFIX}
MAKE_JOBS_SAFE=	yes

PORTDOCS=	dab-manual.pdf
PLIST_FILES+=	bin/dabreceiver bin/fmreceiver

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
IGNORE=	requires FreeBSD 8.0 or later
.endif

do-configure:
	cd ${WRKSRC}/fmreceiver-dab && ${SETENV} ${MAKE_ENV} \
		${QMAKE_DABSTICK} Makefile fmreceiver.pro
	cd ${WRKSRC}/dabreceiver-V2 && ${SETENV} ${MAKE_ENV} \
		${QMAKE_DABSTICK} Makefile dabreceiver.pro

do-build:
	cd ${WRKSRC}/fmreceiver-dab && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS}
	cd ${WRKSRC}/dabreceiver-V2 && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${_MAKE_JOBS}

do-install:
	${INSTALL} ${WRKSRC}/fmreceiver-dab/fmreceiver \
		${WRKSRC}/dabreceiver-V2/dabreceiver \
		${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dab-manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
