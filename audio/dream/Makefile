# $FreeBSD$

PORTNAME=	dream
PORTVERSION=	2.1.1
CATEGORIES=	audio comms hamradio
MASTER_SITES=	SF/drm/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-svn808

MAINTAINER=	takefu@airport.fm
COMMENT=	Software radio for AM and Digital Radio Mondiale (DRM)

LICENSE=	GPLv2

LIB_DEPENDS=	libhamlib.so:comms/hamlib\
		libqwt.so:x11-toolkits/qwt5\
		libfftw3.so:math/fftw3

USE_QT4=	qmake_build moc_build uic_build corelib gui network rcc webkit
QT4_MAKE_ARGS=	INSTALL_ROOT=${STAGEDIR}
USES=		gmake pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=		SNDFILE OGG VORBIS FLAC OPUS SPEEX FAAD FAAC
OPTIONS_RADIO=		DEVICE
OPTIONS_RADIO_DEVICE=	PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	PORTAUDIO SNDFILE
OPTIONS_SUB=		yes

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile

OGG_LIB_DEPENDS=	libogg.so:audio/libogg
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
SPEEX_LIB_DEPENDS=	libspeexdsp.so:audio/speexdsp
FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FAAC_LIB_DEPENDS=	libfaac.so:audio/faac

MANDIRS=	${PREFIX}/share/man/man1
PLIST_FILES=	%%QT_BINDIR%%/dream share/man/man1/dream.1.gz

pre-patch:
	@${REINPLACE_CMD} -e 's|/opt|/usr|g' -e 's|/usr/local|${PREFIX}|g'\
		-e 's|target.path = /usr/bin|target.path = ${STAGEDIR}${QT_BINDIR}|g'\
		-e 's|/usr/share/man/man1|${STAGEDIR}${PREFIX}/share/man/man1|g'\
		-e 's|INSTALLS += documentation||g'\
		 ${WRKSRC}/dream.pro

do-configure:
	cd ${WRKSRC} &&\
		${SETENV} ${MAKE_ENV} ${QMAKE} dream.pro ${QMAKE_ARGS}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/linux/dream.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
