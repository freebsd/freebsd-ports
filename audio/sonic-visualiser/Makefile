PORTNAME=	sonic-visualiser
DISTVERSION=	5.2.1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sonic-visualiser/sonic-visualiser/releases/download/sv_v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for viewing and analysing the contents of music audio files
WWW=		https://www.sonicvisualiser.org/ \
		https://github.com/sonic-visualiser/sonic-visualiser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcapnp.so:devel/capnproto \
		libfftw3.so:math/fftw3 \
		liblrdf.so:textproc/liblrdf \
		liboggz.so:audio/liboggz \
		libopusfile.so:audio/opusfile \
		librubberband.so:audio/rubberband \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libvamp-hostsdk.so:audio/vamp-plugin-sdk

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl meson pkgconfig qt:6 xorg
USE_QT=		base svg tools:build
USE_XORG=	x11
USE_GL=		gl

OPTIONS_DEFINE=		FISHSOUND ID3TAG JACK MAD OSC PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	FISHSOUND ID3TAG JACK MAD PORTAUDIO
OPTIONS_SUB=		yes

FISHSOUND_DESC=		FLAC, Speex and Vorbis codecs support
FISHSOUND_MESON_TRUE=	fishsound
FISHSOUND_LIB_DEPENDS=	libfishsound.so:audio/libfishsound

ID3TAG_MESON_TRUE=	id3tag
ID3TAG_LIB_DEPENDS=	libid3tag.so:audio/libid3tag

JACK_MESON_TRUE=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack

MAD_MESON_TRUE=		mad
MAD_LIB_DEPENDS=	libmad.so:audio/libmad

OSC_DESC=		OpenSound Control support
OSC_MESON_TRUE=		osc
OSC_LIB_DEPENDS=	liblo.so:audio/liblo

PORTAUDIO_MESON_TRUE=	portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

PULSEAUDIO_MESON_TRUE=	pulse
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

post-patch: # remove the bundled vamp-plugin-sdk to avoid possible confusion
	@${RM} -r ${WRKSRC}/vamp-plugin-sdk

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README
.for f in x-sonicvisualiser.desktop x-sonicvisualiser-layer.desktop
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${PREFIX}/share/applications
.endfor

post-install-OSC-on:
	${INSTALL_DATA} ${WRKSRC}/README_OSC.md ${STAGEDIR}${DOCSDIR}/README.OSC

.include <bsd.port.mk>
