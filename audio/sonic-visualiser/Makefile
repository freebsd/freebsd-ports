# $FreeBSD$

PORTNAME=	sonic-visualiser
PORTVERSION=	2.5
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/1675/

MAINTAINER=	uddka@student.kit.edu
COMMENT=	Program for viewing and analysing the contents of music audio files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		librubberband.so:audio/rubberband \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libvamp-hostsdk.so:audio/vamp-plugin-sdk

USES=	autoreconf desktop-file-utils gmake pkgconfig qt:5

GNU_CONFIGURE=	yes
USE_QT=		buildtools_build core gui network qmake_build testlib widgets xml
USE_XORG=	x11
USE_GL=		gl

OPTIONS_DEFINE=	DEBUG FISHSOUND ID3TAG JACK LRDF MAD OGGZ OSC PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	FISHSOUND ID3TAG MAD OGGZ PORTAUDIO
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

FISHSOUND_CONFIGURE_WITH=	fishsound
FISHSOUND_DESC=	FLAC, Speex and Vorbis codecs support
FISHSOUND_LIB_DEPENDS=	libfishsound.so:audio/libfishsound \
			libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis \
			libspeex.so:audio/speex \
			libFLAC.so:audio/flac

ID3TAG_CONFIGURE_WITH=	id3tag
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

JACK_CONFIGURE_WITH=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack

LRDF_CONFIGURE_WITH=	lrdf
LRDF_DESC=	Resource Description Framework support
LRDF_LIB_DEPENDS=	liblrdf.so:textproc/liblrdf

MAD_CONFIGURE_WITH=	mad
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

OGGZ_CONFIGURE_WITH=	oggz
OGGZ_DESC=	Ogg container format support
OGGZ_LIB_DEPENDS=	liboggz.so:audio/liboggz \
			libogg.so:audio/libogg

OSC_CONFIGURE_WITH=	lo
OSC_DESC=	OpenSound Control support
OSC_LIB_DEPENDS=	liblo.so:audio/liblo

PORTAUDIO_CONFIGURE_WITH=	portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

PULSEAUDIO_CONFIGURE_WITH=	pulse
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sonic-visualiser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sonic-visualiser.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/x-sonicvisualiser.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/x-sonicvisualiser-layer.desktop  ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/sv-icon.svg ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-OSC-on:
	${INSTALL_DATA} ${WRKSRC}/README.OSC ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
