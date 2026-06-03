PORTNAME=	hydrogen
DISTVERSION=	1.2.6
CATEGORIES=	audio
MASTER_SITES=	SF/hydrogen/Hydrogen/${DISTVERSION}%20Sources/

MAINTAINER=	FreeBSD@ShaneWare.Biz
COMMENT=	Advanced drum machine
WWW=		http://www.hydrogen-music.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		liblo.so:audio/liblo

USES=		cmake compiler:c++17-lang desktop-file-utils gl libarchive \
		pkgconfig localbase:ldflags qt:6
USE_GL=		gl
USE_LDCONFIG=	yes
USE_QT=		base svg tools

LDFLAGS+=	-lexecinfo
PLIST_SUB=	HYDROGEN_VERSION="${DISTVERSION}"

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${LOCALBASE}/share/man
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen \
		WANT_LIBARCHIVE \
		WANT_QT6

OPTIONS_DEFINE=		ALSA JACK LADSPA LASH OSS PORTAUDIO \
			PORTMIDI PULSEAUDIO RDF RUBBERBAND TEST
OPTIONS_DEFAULT=	JACK LADSPA OSS RDF

PORTMIDI_DESC=		PortMidi support
RDF_DESC=		RDF File support
RUBBERBAND_DESC=	librubberband for time stretching

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>=0:audio/alsa-plugins
ALSA_CMAKE_BOOL=	WANT_ALSA

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	WANT_JACK WANT_JACKSESSION

LADSPA_BUILD_DEPENDS=	ladspa>=0:audio/ladspa
LADSPA_RUN_DEPENDS=	analyseplugin:audio/ladspa
LADSPA_CMAKE_BOOL=	WANT_LADSPA
LADSPA_CMAKE_ON=	-DLADSPA_LIBRARIES:STRING=${LOCALBASE}/lib/ladspa

LASH_LIB_DEPENDS=	liblash.so:audio/lash
LASH_CMAKE_BOOL=	WANT_LASH

OSS_CMAKE_BOOL=		WANT_OSS

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	WANT_PORTAUDIO

PORTMIDI_LIB_DEPENDS=	libportmidi.so:audio/portmidi
PORTMIDI_CMAKE_BOOL=	WANT_PORTMIDI

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WANT_PULSEAUDIO

RDF_LIB_DEPENDS=	liblrdf.so:textproc/liblrdf
RDF_CMAKE_BOOL=		WANT_LRDF

# using librubberband is experimental and current versions have bad timing
# installing the rubberband cli tool still works as before
RUBBERBAND_LIB_DEPENDS=	librubberband.so:audio/rubberband
RUBBERBAND_CMAKE_BOOL=	WANT_RUBBERBAND
#RUBBERBAND_CMAKE_ON=	-DRUBBERBAND_INCLUDE_DIR:STRING=${LOCALBASE}/include/rubberband

TEST_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/cppunit.pc:devel/cppunit
TEST_CMAKE_BOOL=	WANT_CPPUNIT

do-test-TEST-on:
	cd ${WRKSRC} && ${WRKDIR}/.build/src/tests/tests

.include <bsd.port.mk>
