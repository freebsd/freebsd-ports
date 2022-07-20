PORTNAME=	bambootracker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/BambooTracker/BambooTracker/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	BambooTracker-src-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Music tracker for the Yamaha YM2608 (OPNA) sound chip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librtaudio.so:audio/rtaudio \
		librtmidi.so:audio/rtmidi

USES=		compiler:c++14-lang desktop-file-utils gl qmake qt:5 \
		shared-mime-info xorg

USE_GL=		gl
USE_QT=		buildtools core gui multimedia network widgets \
		linguisttools_build

DATADIR=	${PREFIX}/share/BambooTracker
DOCSDIR=	${PREFIX}/share/doc/BambooTracker
EXAMPLESDIR=	${PREFIX}/share/examples/BambooTracker

WRKSRC=		${WRKDIR}/BambooTracker-src-${DISTVERSIONPREFIX}${DISTVERSION}

OPTIONS_DEFINE=		ALSA EXAMPLES JACK NLS PULSEAUDIO
OPTIONS_DEFAULT=	PULSEAUDIO
OPTIONS_SUB=		yes

ALSA_DESC=	ALSA audio architecture support (EXPERIMENTAL)
JACK_DESC=	JACK audio server support (EXPERIMENTAL)

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
JACK_LIB_DEPENDS=	libjack.so:audio/jack
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
QMAKE_ARGS+=	CONFIG+="use_alsa"
.endif

.if ${PORT_OPTIONS:MJACK}
QMAKE_ARGS+=	CONFIG+="jack_has_rename" CONFIG+="use_jack"
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
QMAKE_ARGS+=	CONFIG+="use_pulse"
.endif

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${MANPREFIX}/share/man/man1
	${MV} ${STAGEDIR}${PREFIX}/share/BambooTracker/demos/* ${STAGEDIR}${EXAMPLESDIR}/
	${MV} ${STAGEDIR}${MANPREFIX}/share/man/en/man1/BambooTracker.1 ${STAGEDIR}${MANPREFIX}/share/man/man1/
	${RMDIR} ${STAGEDIR}${PREFIX}/share/BambooTracker/demos
	${RMDIR} ${STAGEDIR}${MANPREFIX}/share/man/en/man1
	${RMDIR} ${STAGEDIR}${MANPREFIX}/share/man/en

# maintainer targets
try-latest: clean extract
	@${RM} -rf ${WRKSRC}
	@git clone --recurse-submodules https://github.com/BambooTracker/BambooTracker.git ${WRKSRC}

.include <bsd.port.mk>
