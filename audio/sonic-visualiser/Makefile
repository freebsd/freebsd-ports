PORTNAME=	sonic-visualiser
DISTVERSION=	4.0.1
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/2607/

MAINTAINER=	uddka@student.kit.edu
COMMENT=	Program for viewing and analysing the contents of music audio files
WWW=		https://www.sonicvisualiser.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcapnp.so:devel/capnproto \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		liblrdf.so:textproc/liblrdf \
		libogg.so:audio/libogg \
		liboggz.so:audio/liboggz \
		libopusfile.so:audio/opusfile \
		librubberband.so:audio/rubberband \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libvamp-hostsdk.so:audio/vamp-plugin-sdk

USES=		autoreconf compiler:c++11-lang desktop-file-utils dos2unix gmake gl pkgconfig qt:5 xorg
DOS2UNIX_FILES=	convert.pro
USE_QT=		buildtools:build core gui network qmake:build svg testlib widgets xml
USE_XORG=	x11
USE_GL=		gl

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		DEBUG FISHSOUND ID3TAG JACK MAD OSC PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	FISHSOUND ID3TAG JACK MAD PORTAUDIO
OPTIONS_SUB=		yes

DEBUG_CONFIGURE_ENABLE=	debug

FISHSOUND_DESC=		FLAC, Speex and Vorbis codecs support
FISHSOUND_CONFIGURE_WITH=	fishsound
FISHSOUND_LIB_DEPENDS=	libfishsound.so:audio/libfishsound \
			libvorbis.so:audio/libvorbis \
			libspeex.so:audio/speex \
			libFLAC.so:audio/flac

ID3TAG_CONFIGURE_WITH=	id3tag
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

JACK_CONFIGURE_WITH=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack

MAD_CONFIGURE_WITH=	mad
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

OSC_DESC=		OpenSound Control support
OSC_CONFIGURE_WITH=	lo
OSC_LIB_DEPENDS=	liblo.so:audio/liblo

PORTAUDIO_CONFIGURE_WITH=	portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

PULSEAUDIO_CONFIGURE_WITH=	pulse
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

post-patch: # remove the bundled vamp-plugin-sdk to avoid possible confusion
	@${RM} -r ${WRKSRC}/vamp-plugin-sdk
	# workaround for https://sourceforge.net/p/sv1/bugs/280/, also see Bug#236000
	@${FIND} ${WRKSRC} -name "*.pro" -o -name "*.pri" | ${XARGS} ${REINPLACE_CMD} -e 's|-Werror| |'

do-install:
.for f in sonic-visualiser piper-vamp-simple-server piper-convert checker/vamp-plugin-load-checker
	${INSTALL_PROGRAM} ${WRKSRC}/$f ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in sonic-visualiser.desktop x-sonicvisualiser.desktop x-sonicvisualiser-layer.desktop
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${PREFIX}/share/applications
.endfor
	${INSTALL_DATA} ${WRKSRC}/icons/sv-icon.svg ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-OSC-on:
	${INSTALL_DATA} ${WRKSRC}/README.OSC ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
